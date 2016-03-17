/* kill.c - kill */

#include "conf.h"
#include "kernel.h"
#include "proc.h"
#include "sem.h"
#include "mem.h"
#include "io.h"
#include "q.h"
#include "sleep.h"

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

      case PRCURR:
        pptr->pstate = PRFREE;	/* suicide */
        resched();

      case PRWAIT:
        semaph[pptr->psem].semcnt++;
        dequeue(pid);
        pptr->pstate = PRFREE;
        break;

      case PRSLEEP:
        // Add my wait time to the next process in the delta queue's wait time
        if (q[pid].qnext < NPROC){
            q[q[pid].qnext].qkey += q[pid].qkey;
        }

      case PRREADY:
        dequeue(pid);

	  default:	pptr->pstate = PRFREE;
	}
	restore(ps);
	return(OK);
}
