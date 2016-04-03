/* create.c - create, newpid */
#include<stdarg.h>
#include "conf.h"
#include "kernel.h"
#include "proc.h"
#include "mem.h"
#include "io.h"

LOCAL newpid();

/*------------------------------------------------------------------------
 *  create  -  create a process to start running a procedure
 *------------------------------------------------------------------------
 */
SYSCALL create(void (*procaddr)(),	/* procedure address            */
        int ssize,              /* stack size in words          */
        int priority,           /* process priority > 0         */
        char *name,             /* name (for debugging)         */
        int nargs,              /* number of args that follow   */
        ...)               /* arguments (treated like an   */
                                /* array in the code)           */
{
    int	pid;                    /* stores new process id	*/
	struct	pentry	*pptr;		/* pointer to proc. table entry */
	int	i;
    int	*a;                     /* points to list of args	*/
    int	*saddr;                 /* stack address		*/
    sigset_t	ps;                 /* saved processor status	*/
	int	INITRET();
    int args[MAXARGS];          /* variadic arguments are copied here */
    va_list ap;                 /* used to iterate through variadic args */

    disable(ps);
	ssize = roundew(ssize);
    // Removed check for isodd, since we're using posix contexts, doesn't have to align to word boundary
    if ( ssize < MINSTK ||
         priority < 1 ||
         (pid=newpid()) == SYSERR  ||
        (((int)(saddr=getstk(ssize))) == SYSERR ) ||
         nargs > MAXARGS) {
		restore(ps);
		return(SYSERR);
	}
	numproc++;
	pptr = &proctab[pid];
	pptr->pstate = PRSUSP;
	for (i=0 ; i<PNMLEN && (pptr->pname[i]=name[i])!=0 ; i++)
		;
	pptr->pprio = priority;
	pptr->pbase = (int)saddr;
	pptr->pstklen = ssize;
	pptr->psem = 0;
	pptr->phasmsg = FALSE;
	pptr->plimit = (int)(saddr - ssize + 1);
	pptr->pargs = nargs;
    pptr->paddr = procaddr;

    //Don't need to save registers, since we're using a POSIX context
    //for (i=0 ; i<PNREGS ; i++)
    //    pptr->pregs[i]=INITREG;
    //pptr->pregs[PC] = pptr->paddr = (int)procaddr;
    //pptr->pregs[PS] = INITPS;
    //
    //a = (&args) + (nargs-1);	/* point to last argument	*/
    //for ( ; nargs > 0 ; nargs--)	/* machine dependent; copy args	*/
    //	*saddr-- = *a--;	/* onto created process' stack	*/
    //*saddr = (int)INITRET;		/* push on return address	*/
    //pptr->pregs[SP] = (int)saddr;

    /* Create a context */
    pptr->posix_ctxt=posix_ctxt_init;

    pptr->posix_ctxt.uc_stack.ss_flags = 0;
    pptr->posix_ctxt.uc_stack.ss_size  = ssize;
    pptr->posix_ctxt.uc_stack.ss_sp    = (void *)pptr->plimit; // Plimit points to shallow end of stack as required by ss_sp
    pptr->posix_ctxt.uc_link           = &end_game_ctxt; // Since we're using u_context, link to end_game_ctxt on return instead of calling INITRET

    /* No easy way to pass the args array to makecontext, since it uses variadic arguments. Instead, just hardcode 10 args variables and pass them as needed.
        Will break if passed more than 10 args */
    va_start(ap, nargs);
    for (i=0; i<nargs; ++i){
        args[i]=va_arg(ap, int);
    }
    va_end(ap);

    int arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10;
    switch (nargs)
    {
    case 10:
        arg10=args[9];
    case 9:
        arg9=args[8];
    case 8:
        arg8=args[7];
    case 7:
        arg7=args[6];
    case 6:
        arg6=args[5];
    case 5:
        arg5=args[4];
    case 4:
        arg4=args[3];
    case 3:
        arg3=args[2];
    case 2:
        arg2=args[1];
    case 1:
        arg1=args[0];
    case 0:
        break;
    default:
        perror("unknown number of args in create");
        exit(1);
    }

    switch (nargs) {
    case 10:
        makecontext(&pptr->posix_ctxt, procaddr, 10, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
        break;
    case 9:
        makecontext(&pptr->posix_ctxt, procaddr, 9, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        break;
    case 8:
        makecontext(&pptr->posix_ctxt, procaddr, 8, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;
    case 7:
        makecontext(&pptr->posix_ctxt, procaddr, 7, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        break;
    case 6:
        makecontext(&pptr->posix_ctxt, procaddr, 6, arg1, arg2, arg3, arg4, arg5, arg6);
        break;
    case 5:
        makecontext(&pptr->posix_ctxt, procaddr, 5, arg1, arg2, arg3, arg4, arg5);
        break;
    case 4:
        makecontext(&pptr->posix_ctxt, procaddr, 4, arg1, arg2, arg3, arg4);
        break;
    case 3:
        makecontext(&pptr->posix_ctxt, procaddr, 3, arg1, arg2, arg3);
        break;
    case 2:
        makecontext(&pptr->posix_ctxt, procaddr, 2, arg1, arg2);
        break;
    case 1:
        makecontext(&pptr->posix_ctxt, procaddr, 1, arg1);
        break;
    case 0:
        makecontext(&pptr->posix_ctxt, procaddr, 0);
        break;
    }

	restore(ps);
	return(pid);
}

/*------------------------------------------------------------------------
 * newpid  --  obtain a new (free) process id
 *------------------------------------------------------------------------
 */
LOCAL	newpid()
{
	int	pid;			/* process id to return		*/
	int	i;

	for (i=0 ; i<NPROC ; i++) {	/* check all NPROC slots	*/
		if ( (pid=nextproc--) <= 0)
			nextproc = NPROC-1;
		if (proctab[pid].pstate == PRFREE)
			return(pid);
	}
	return(SYSERR);
}
