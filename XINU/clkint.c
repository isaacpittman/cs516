/* clkint.s -  clkint */

/*------------------------------------------------------------------------
/* clkint  --  real-time clock interrupt service routine 
/*------------------------------------------------------------------------
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
