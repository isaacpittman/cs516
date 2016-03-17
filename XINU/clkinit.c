/* clkinit.c - clkinit */

#include "conf.h"
#include "kernel.h"
#include "sleep.h"

/* real-time clock variables and sleeping process queue pointers	*/

#ifdef	RTCLOCK
int     count6;			/* counts in 60ths of a second 6-0	*/
int     defclk;			/* non-zero, then deferring clock count */
int     clkdiff;		/* deferred clock ticks			*/
int     slnempty;		/* FALSE if the sleep queue is empty	*/
int     *sltop;			/* address of key part of top entry in	*/
                        /* the sleep queue if slnempty==TRUE	*/
int     clockq;			/* head of queue of sleeping processes  */
int     preempt;        /* preemption counter.	Current process */
                        /* is preempted when it reaches zero;	*/
                        /* set in resched; counts in ticks	*/
int     clkruns;        /* set TRUE iff clock exists by setclkr	*/
#else
int	clkruns = FALSE;	/* no clock configured; be sure sleep	*/
#endif                  /*   doesn't wait forever		*/

/*
 *------------------------------------------------------------------------
 * clkinit - initialize the clock and sleep queue (called at startup)
 *------------------------------------------------------------------------
 */
clkinit()
{
    //int *vector;

    //vector = (int *) CVECTOR;	/* set up interrupt vector	*/
    //*vector++ = clkint;
    //*vector = DISABLE;
    //setclkr();

    clkruns = TRUE;             /* Set clkruns TRUE, since clock is always defined on modern systems */

    preempt = QUANTUM;          /* initial time quantum		*/
    count6 = 6;                 /* 60ths of a sec. counter	*/
    slnempty = FALSE;           /* initially, no process asleep	*/
    clkdiff = 0;                /* zero deferred ticks		*/
    defclk = 0;                 /* clock is not deferred	*/
	clockq = newqueue();		/* allocate clock queue in q	*/


    /* Create a signal handler to simulate a clock interrupt */
    sigset_t            mask;
    struct itimerval    timer;
    struct sigaction    sigclktick;

    sigemptyset(&mask);
    sigclktick.sa_handler = &clkint;
    sigaction (SIGVTALRM, &sigclktick, NULL);

    /* Initial alarm */
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = TICK_LENGTH_USEC;

    /* Subsequent alarm intervals */
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = TICK_LENGTH_USEC;

    write(1, "\nStarting clock interrupt timer\n", 32);
    setitimer (ITIMER_VIRTUAL, &timer, NULL);
}

/* Every clock tick... */
void clkint (int signum)
{
    //Is this the 6th interrupt?
    if (--count6>0){
        //no => return
        return;
    } else {
        //yes=> reset counter&continue
        count6=6;
        //Are clock ticks deferred?
        if (defclk==0) {
            //no => go process this tick
            //notdef
            //Is sleep queue nonempty?
            if (slnempty!=0) {
                //yes=> decrement delta key on first process calling wakeup if it reaches zero
                (*sltop)--;
                if (*sltop<1) {
                    wakeup();
                }
            }
            //no => go process preemption
            //clpreem
            preempt--;
            if (preempt>0) {
                return;
            } else {
                resched();
            }
        } else {
            //yes=> count in clkdiff and return quickly
            clkdiff++;
            return;
        }
    }
}
/*
    .globl	_clkint
_clkint:
    dec	_count6			/ Is this the 6th interrupt?
    bpl	clret			/  no => return
    mov	$6,_count6		/  yes=> reset counter&continue
    tst     _defclk			/ Are clock ticks deferred?
    beq     notdef			/  no => go process this tick
    inc     _clkdiff		/  yes=> count in clkdiff and
    rtt				/        return quickly
notdef:
    tst     _slnempty		/ Is sleep queue nonempty?
    beq     clpreem			/  no => go process preemption
    dec     *_sltop			/  yes=> decrement delta key
    bpl	clpreem			/        on first process,
    mov	r0,-(sp)		/        calling wakeup if
    mov	r1,-(sp)		/        it reaches zero
    jsr	pc,_wakeup		/        (interrupt routine
    mov	(sp)+,r1		/         saves & restores r0
    mov	(sp)+,r0		/         and r1; C doesn't)
clpreem:
    dec	_preempt		/ Decrement preemption counter
    bpl	clret			/   and call resched if it
    mov	r0,-(sp)		/   reaches zero
    mov	r1,-(sp)		/	(As before, interrupt
    jsr	pc,_resched		/	 routine must save &
    mov	(sp)+,r1		/	 restore r0 and r1
    mov	(sp)+,r0		/	 because C doesn't)
clret:
    rtt				/ Return from interrupt
 */

