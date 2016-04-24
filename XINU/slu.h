/* slu.h */

/* standard serial line unit device constants */

#define	SLUENABLE	0100		/* device interrupt enable bit	*/  /*01000000*/
#define	SLUREADY	0200		/* device ready bit		*/          /*10000000*/
#define	SLUREADYOFF	0177		/* device ready bit		*/          /*01111111*/
#define	SLUREADYON	0200		/* device ready bit		*/          /*10000000*/
#define	SLUDISABLE	0000		/* device interrupt disable mask*/
#define	SLUTBREAK	0001		/* transmitter break-mode bit	*/
#define	SLUERMASK	0170000		/* mask for error flags on input*/
#define	SLUCHMASK	0377		/* mask for input character	*/

/* SLU device register layout and correspondence to vendor's names	*/

struct	csr	{
	unsigned short	crstat;		/* receiver control and status	(RCSR)	*/
	unsigned short	crbuf;		/* receiver data buffer		(RBUF)	*/
	unsigned short	ctstat;		/* transmitter control & status (XCSR)	*/
	unsigned short	ctbuf;		/* transmitter data buffer	(XBUF)	*/
};
