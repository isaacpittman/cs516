/* kernel.h - disable, enable, halt, restore, isodd, min */

/* Symbolic constants used throughout Xinu */

// Linux platform includes for signal and context management

#include "signal.h"
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <ucontext.h>

//typedef	char		Bool;		/* Boolean type			*/
#define Bool		char
#define	FALSE		0		/* Boolean constants		*/
#define	TRUE		1
// #define	NULL		(void *)0	/* Null pointer for linked lists*/
#define	NULLCH		'\0'		/* The null character		*/
#define	NULLSTR		""		/* Pointer to empty string	*/
#define	SYSCALL		int		/* System call declaration	*/
#define	LOCAL		static		/* Local procedure declaration	*/
#define	INTPROC		int		/* Interrupt procedure  "	*/
#define	ISR		void		/* interrupt signal handler	*/
#define	PROCESS		int		/* Process declaration		*/
#define	RESCHYES	1		/* tell	ready to reschedule	*/
#define	RESCHNO		0		/* tell	ready not to resch.	*/
#define	MININT		0100000		/* minimum integer (-32768)	*/
#define	MAXINT		0077777		/* maximum integer		*/
#define	LOWBYTE		0377		/* mask for low-order 8 bits	*/
#define	HIBYTE		0177400		/* mask for high 8 of 16 bits	*/
#define	LOW16		0177777		/* mask for low-order 16 bits	*/
// #define	SP		6		/* reg.	6 is stack pointer	*/
// #define	PC		7		/* reg.	7 is program counter	*/
// #define	PS		8		/* proc. status	in 8th reg. loc	*/
#define	MINSTK		8192		/* minimum process stack size	*/
#define	NULLSTK		8192		/* process 0 stack size		*/
#define	MAXARGCNT	5		/* maximum int arguments to create	*/
// #define	DISABLE		0340		/* PS to disable interrupts	*/
#define RTCLOCK
#define FREE_SIZE	(1024*1024)
#define RTCLOCK_SYM

/* Universal return constants */

#define	OK		 1		/* system call ok		*/
#define	SYSERR		-1		/* system call failed		*/
					/*  (usu. defined as ^B)	*/
/* Initialization constants */

#define	INITARGC	1		/* initial process argc       	*/
#define	INITARG		111		/* initial process argument     */
#define	INITSTK		8192		/* initial process stack	*/
#define	INITPRIO	20		/* initial process priority	*/
#define	INITNAME	"m_fun"		/* initial process name		*/
#define	INITRET		userret		/* processes return address	*/
#define INITARGSC   0       /* number of arguments passed to init thread */
// #define	INITPS		0		/* initial process PS		*/
// #define	INITREG		0		/* initial register contents	*/
#define	QUANTUM		10		/* clock ticks until preemption	*/
#define TICK_LENGTH_USEC 16667   /* clock tick length in microseconds */
#define MAGIC		0xDEADBEEF	/* magic for nullproc stack base*/
#define MAXARGS     10      /* max number of arguments that can be passed to create */

/* Miscellaneous utility inline functions */

#define	isodd(x)	(01&(int)(x))
#define	min(a,b)	( (a) < (b) ? (a) : (b) )
/************************************************************************
#define	disable(ps)	asm("mfps ~ps");asm("mtps $0340")
#define	restore(ps)	asm("mtps ~ps")	/* restore interrupt status	*
#define	enable()	asm("mtps $000")/* enable interrupts		*
#define	pause()		asm("wait")	/* machine "wait for interr."	*
#define	halt()		asm("halt")	/* machine halt	instruction	*
************************************************************************/
#define	disable(ps)	sigprocmask(SIG_SETMASK, &full_block, &ps);
#define	restore(ps)	sigprocmask(SIG_SETMASK, &ps, NULL);
#define	enable()	sigprocmask(SIG_SETMASK, &full_unblock, NULL);
#define	pause()		pause();

extern	int	rdyhead, rdytail;
extern	int	preempt;
extern  sigset_t full_block, full_unblock;
extern  ucontext_t posix_ctxt_init, end_game_ctxt;
