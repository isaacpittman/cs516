/* initialize.c - nulluser, sysinit */

#include "cli.h"
#include "conf.h"
#include "kernel.h"
#include "proc.h"
#include "sem.h"
#include "sleep.h"
#include "mem.h"
//#include <tty.h>
#include "q.h"
#include "io.h"
//#include <disk.h>
//#include <network.h>

extern	void	main_fun();			/* address of user's main prog	*/
extern  void    end_game();         /* end context, kill -> resched */
extern  void    procA(int);         /* process created by main_fun */
extern  void    procB(int, int);    /* process created by main_fun */
extern  void    procC(int, int);    /* process created by main_fun */

/* Declarations of major kernel variables */

struct	pentry	proctab[NPROC]; /* process table			*/
int     nextproc;               /* next process slot to use in create	*/
struct	sentry	semaph[NSEM];	/* semaphore table			*/
int     nextsem;                /* next semaphore slot to use in screate*/
struct	qent	q[NQENT];       /* q table (see queue.c)		*/
int     nextqueue;              /* next slot in q structure to use	*/
int     *maxaddr;               /* max memory address (set by sizmem)	*/
#ifdef	NDEVS
struct	intmap	intmap[NDEVS];	/* interrupt dispatch table		*/
#endif
struct	mblock	memlist;        /* list of free memory blocks		*/
#ifdef	Ntty
//struct  tty     tty[Ntty];	/* SLU buffers and mode control		*/
#endif

sigset_t    full_block, full_unblock;       /* Masks to block or unblock interrupts during critical sections */
ucontext_t  posix_ctxt_init, end_game_ctxt; /* TODO: Comment */

/* active system status */

int	numproc;                    /* number of live user processes	*/
int	currpid;                    /* id of currently running process	*/
int	reboot = 0;                 /* non-zero after first boot		*/

#ifdef  RTCLOCK
extern int  clkruns;            /* TODO: Comment */
#endif

int	rdyhead,rdytail;            /* head/tail of ready list (q indexes)	*/
char	vers[] = VERSION;       /* Xinu version printed at startup	*/

/************************************************************************/
/***				NOTE:				      ***/
/***								      ***/
/***   This is where the system begins after the C environment has    ***/
/***   been established.  Interrupts are initially DISABLED, and      ***/
/***   must eventually be enabled explicitly.  This routine turns     ***/
/***   itself into the null process after initialization.  Because    ***/
/***   the null process must always remain ready to run, it cannot    ***/
/***   execute code that might cause it to be suspended, wait for a   ***/
/***   semaphore, or put to sleep, or exit.  In particular, it must   ***/
/***   not do I/O unless it uses kprintf for polled output.           ***/
/***								      ***/
/************************************************************************/

/*------------------------------------------------------------------------
 *  nulluser  -- initialize system and become the null process (id==0)
 *------------------------------------------------------------------------
 */

int up=0;

LOCAL   sysinit();
void    idle_thread();
void    main_fun(int);

//int nulluser()				/* babysit CPU when no one home */
int main(int argc, char *argv[])
{
    int     userpid, main_fun_cnt;  /* TODO: comment */
    sigset_t ps;    /* TODO: Comment */

    main_fun_cnt = 1;

    sigfillset(&full_block);
    sigdelset(&full_block, SIGBUS);
    sigdelset(&full_block, SIGFPE);
    sigdelset(&full_block, SIGILL);
    sigdelset(&full_block, SIGSEGV);
    sigemptyset(&full_unblock);

/*
	kprintf("\n\nXinu Version %s", vers);
	if (reboot++ < 1)
		kprintf("\n");
	else
		kprintf("   (reboot %d)\n", reboot);
*/
    /* TODO: Comment */
    if(getcontext(&posix_ctxt_init) == -1){
        perror("getcontext failed in initialize.c");
        exit(5);
    }

    end_game_ctxt=posix_ctxt_init;

	sysinit();			/* initialize all of Xinu */

    end_game_ctxt.uc_stack.ss_sp    = (void *)((int)getstk(MINSTK)-MINSTK); /* TODO: Comment */
    end_game_ctxt.uc_stack.ss_size  = MINSTK;
    end_game_ctxt.uc_stack.ss_flags = 0;
    makecontext(&end_game_ctxt, end_game, 0);

/*
	kprintf("%u real mem\n",(unsigned)maxaddr+(unsigned)sizeof(int));
	kprintf("%u avail mem\n",
		(unsigned)maxaddr-(unsigned)(&end)+(unsigned)sizeof(int));
	kprintf("clock %sabled\n\n", clkruns==1?"en":"dis");
*/
	/* create a process to execute the user's main program */

    /* TODO: Comment */
    up = userpid = create(main_fun,INITSTK,INITPRIO,INITNAME,INITARGSC);

    /* TODO: Comment */
    setcontext (&(proctab[NULLPROC].posix_ctxt));

    write(1, "\nBAD THINGS ARE HAPPENING\n", 26);
	return;				/* unreachable			*/
}

/*------------------------------------------------------------------------
 *  sysinit  --  initialize all Xinu data structures and devices
 *------------------------------------------------------------------------
 */
LOCAL	sysinit()
{
	int	i;
	struct	pentry	*pptr;
	struct	sentry	*sptr;
	struct	mblock	*mptr;

	numproc  = 0;			/* initialize system variables */
	nextproc = NPROC-1;
	nextsem  = NSEM-1;
	nextqueue= NPROC;		/* q[0..NPROC-1] are processes */

	memlist.mnext = mptr =		/* initialize free memory list */
      (struct mblock *) malloc(FREE_SIZE);
    if(mptr == NULL) {
        perror("malloc failed ");
        exit(3);
    }
	mptr->mnext = (struct mblock *)NULL;
//	mptr->mlen = truncew((unsigned)maxaddr-NULLSTK-(unsigned)&end);
    mptr->mlen = truncew((FREE_SIZE)-(NULLSTK)); /* TODO: Comment */

	for (i=0 ; i<NPROC ; i++)	/* initialize process table */
		proctab[i].pstate = PRFREE;

	pptr = &proctab[NULLPROC];	/* initialize null process entry */
	pptr->pstate = PRCURR;
	pptr->pprio = 0;
    /* TODO: Comment */
    for(i=0; i<7; ++i){
        pptr->pname[i] = *("prnull" +i);
    }
    //pptr->plimit = ( (int)maxaddr ) - NULLSTK - sizeof(int);
    pptr->plimit = ( (int)mptr + (FREE_SIZE) - (NULLSTK) - 1); /* TODO: Comment */
    //pptr->pbase = maxaddr;
    // last byte address in pbase, but need an int address
    // 4 bytes away from the end for the following MAGIC assignment
    // TODO: Clarify MAGIC
    pptr->pbase = (int)mptr + (FREE_SIZE) - 1; /* TODO: Comment */
    *( (int *)(pptr->pbase - 3) ) = MAGIC;
    pptr->paddr = idle_thread;
	pptr->phasmsg = FALSE;
	pptr->pargs = 0;
    pptr->posix_ctxt = posix_ctxt_init; /* TODO: Comment */

    /* TODO: Comment */
    pptr->posix_ctxt.uc_stack.ss_sp     = (void *)pptr->plimit;
    pptr->posix_ctxt.uc_stack.ss_size   =   NULLSTK;
    pptr->posix_ctxt.uc_stack.ss_flags  = 0;
    pptr->posix_ctxt.uc_link            = &end_game_ctxt;

    makecontext(&(pptr->posix_ctxt), idle_thread, 0);
	currpid = NULLPROC;

	for (i=0 ; i<NSEM ; i++) {	/* initialize semaphores */
		(sptr = &semaph[i])->sstate = SFREE;
		sptr->sqtail = 1 + (sptr->sqhead = newqueue());
	}

	rdytail = 1 + (rdyhead=newqueue());/* initialize ready list */

#ifdef	MEMMARK
	_mkinit();			/* initialize memory marking */
#endif
#ifdef	RTCLOCK
	clkinit();			/* initialize r.t.clock	*/
#endif
#ifdef	Ndsk
	dskdbp= mkpool(DBUFSIZ,NDBUFF);	/* initialize disk buffers */
	dskrbp= mkpool(DREQSIZ,NDREQ);
#endif

    // for ( i=0 ; i<NDEVS ; i++ )	/* initialize devices */
    //	init(i);

	return(OK);
}

void idle_thread(){
    int i=1, j;
    enable();   /* enable interrupts */
    while(1) {
        write(1, "#", 1);
        if(i){
            if (resume(up) == SYSERR) {
                  write(1, "\ncreate 0 failed\n", 17);
            }
            i=0;
        }
        resched();
        for(j=0; j<100000000; ++j);
    }
}

void main_fun(int arg){

    int i, j=0, k, gig_count, lcount;
    char *name = "tproc";
    int sem1, pidA, pidB, pidC, main_pid;

    main_pid = getpid();
    write(1, "\nINIT: MAIN FUNCTION IS ALIVE\n", 30);

    if((sem1 = screate(0)) == SYSERR){
        write(1, "\nsem create failed\n", 19);
    }

    if((pidA = create(procA, MINSTK, 20, name, 1, sem1)) == SYSERR){
        write(1, "\ncreate A failed\n", 17);
    }
    if((pidB = create(procB, MINSTK, 20, name, 2, sem1, pidA)) == SYSERR){
        write(1, "\ncreate B failed\n", 17);
    }
    if((pidC = create(procC, MINSTK, 20, name, 2, main_pid, 30)) == SYSERR){
        write(1, "\ncreate C failed\n", 17);
    }

    write(1, "\nINIT: main function has created procs A B and C\n",49);
    write(1, "\nINIT: main function about to suspend self\n", 43);

    if(resume(pidA) == SYSERR ||
       resume(pidB) == SYSERR ||
       resume(pidC) == SYSERR){
        write(1, "\nmain resume of A B and C failed\n", 33);
    }

    if(suspend(main_pid) == SYSERR){
        write(1, "\nmain suspend failed\n", 21);
    }
    write(1, "\nINIT: main function has been resumed\n", 38);

    for (i=0; i<NPROC; ++i) {
        if (i==main_pid || i==NULLPROC)
            continue;
        if (proctab[i].pstate != PRFREE) {
            write(1,"\nSome proc is still alive. Sleeping main for 5...\n", 50);
            sleep(5);
            i=0;
        }
    }

    write(1, "\nINIT: proc table empty, goodbye\n", 33);

}

void end_game(){
    write(1,"<>",2);
    kill(getpid());
}

void procA(int arg){
    write(1, "\nA: process A is alive\n", 22);
    write(1, "\nA: process A is about to wait on a sem\n", 39);

    if(wait(arg) == SYSERR){
        write(1, "\nin A wait failed\n", 18);
    }

    write(1, "\nA: process A is awake from sem, will wait for msg\n", 51);

    if(receive() == SYSERR){
        write(1, "\nin A receive failed\n", 21);
    }

    write(1, "\nA: process A has received a msg, goodbye\n", 42);

}

void procB(int arg1, int arg2){
    write(1, "\nB: process B is alive\n", 22);
    write(1, "\nB: process B is about to sleep for 2 seconds\n", 45);

    if(sleep(2) == SYSERR){
        write(1, "\nin B sleep failed\n", 19);
    }

    write(1, "\nB: process B is awake from sleep, will signal sem\n", 51);

    if(signal(arg1) == SYSERR){
        write(1, "\nin B signal failed\n", 20);
    }
    write(1, "\nB: process B is again to sleep for 2 seconds\n", 45);

    if(sleep(2) == SYSERR){
        write(1, "\nin B sleep2 failed\n", 20);
    }

    write(1, "\nB: process B is awake from sleep, will send msg to A\n", 54);

    if(send(arg2, 111) == SYSERR){
        write(1, "\nin B msg send failed\n",22);
    }

    write(1, "\nB: process B is about to sleep for 2 seconds\n", 45);

    if(sleep(2) == SYSERR){
        write(1, "\nin B sleep3 failed\n", 20);
    }

    write(1, "\nB: process B is awake from sleep, goodbye\n", 43);

}

void procC(int arg1, int arg2){
    write(1, "\nC: process C is alive\n", 22);
    write(1, "\nC: process C is about to sleep for 30 seconds\n", 48);

    if(sleep(1) == SYSERR){
        write(1, "\nin C sleep failed\n", 19);
    }

    write(1, "\nC: process C is awake from sleep, will resume INIT\n", 52);

    if(resume(arg1) == SYSERR){
        write(1, "\nin C resume failed\n", 20);
    }

    write(1, "\nC: process C is starting the CLI\n", 34);

    start_cli();
}

