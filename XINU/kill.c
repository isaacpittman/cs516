/* kill.c - kill */

#include "conf.h"
#include "kernel.h"
#include "proc.h"
#include "sem.h"
#include "mem.h"
#include "io.h"

/*------------------------------------------------------------------------
 * kill  --  kill a process and remove it from the system
 *------------------------------------------------------------------------
 */
SYSCALL kill(int pid)			/* process to kill              */
{
	struct	pentry	*pptr;		/* points to proc. table for pid*/
	char	ps;

	disable(ps);
	if (isbadpid(pid) || (pptr= &proctab[pid])->pstate==PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	freestk(pptr->pbase, pptr->pstklen);
	switch (pptr->pstate) {

	  case PRCURR:	pptr->pstate = PRFREE;	/* suicide */
			resched();

	  case PRWAIT:	semaph[pptr->psem].semcnt++;
						/* fall through */
	  case PRSLEEP:
	  case PRREADY:	dequeue(pid);

	  default:	pptr->pstate = PRFREE;
	}
	restore(ps);
	return(OK);
}
