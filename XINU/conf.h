/* conf.h (GENERATED FILE; DO NOT EDIT) */

#define	NULLPTR	(void *)0

/* Device table declarations */
struct	devsw	{			/* device table entry */
	int	dvnum;
	int	(*dvinit)();
	int	(*dvopen)();
	int	(*dvclose)();
	int	(*dvread)();
	int	(*dvwrite)();
	int	(*dvseek)();
	int	(*dvgetc)();
	int	(*dvputc)();
	int	(*dvcntl)();
//	int	dvcsr;
	struct csr	*dvcsr;
	int	dvivec;
	int	dvovec;
// 	int	(*dviint)();
	void	(*dviint)();
	void	(*dvoint)();
	void	*dvioblk;
	int	dvminor;
	};

extern	struct	devsw devtab[];		/* one entry per device */


/* Device name definitions */

#define	CONSOLE     0			/* type tty      */
#define	OTHER       1			/* type tty      */
#define	RING0IN     2			/* type dlc      */
#define	RING0OUT    3			/* type dlc      */
#define	DISK0       4			/* type dsk      */
#define	FILE1       5			/* type df       */
#define	FILE2       6			/* type df       */
#define	FILE3       7			/* type df       */
#define	FILE4       8			/* type df       */

/* Control block sizes */

/************************************************************
#define	Ntty	2
#define	Ndlc	2
#define	Ndsk	1
#define	Ndf	4

#define	NDEVS	9
************************************************************/
#define	Ntty	1
#define	NDEVS	1
/* Declarations of I/O routines referenced */

extern	int	ttyinit();
extern	int	ttyopen();
extern	int	ionull();
extern	int	ttyread();
extern	int	ttywrite();
extern	int	ioerr();
extern	int	ttycntl();
extern	int	ttygetc();
extern	int 	ttyputc(struct devsw *devptr, char ch);
extern	void	ttyiin();
extern	void	ttyoin();

/*************************************************
extern	int	dlcinit();
extern	int	dlcread();
extern	int	dlcwrite();
extern	int	dlccntl();
extern	int	dlcputc();
extern	int	dlciin();
extern	int	dlcoin();
extern	int	dsinit();
extern	int	dsopen();
extern	int	dsread();
extern	int	dswrite();
extern	int	dsseek();
extern	int	dscntl();
extern	int	dsinter();
extern	int	lfinit();
extern	int	lfclose();
extern	int	lfread();
extern	int	lfwrite();
extern	int	lfseek();
extern	int	lfgetc();
extern	int	lfputc();
**************************************************/

/* Configuration and Size Constants */


// #define MEMMARK				/* define if memory marking used*/
// #define NNETS	    1			/* number of XINU ring networks */
					/* (remove if there are 0)      */
#define	NPROC	    10			/* number of user processes	*/
#define	NSEM	    50			/* number of semaphores		*/
#define	VERSION	    "6.09b (3/1/83)"	/* label printed at startup	*/
