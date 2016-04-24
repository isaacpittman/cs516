/* ttyoin.c - ttyoin */

#include "conf.h"
#include "kernel.h"
#include "tty.h"
#include "io.h"
#include "slu.h"

/*------------------------------------------------------------------------
 *  ttyoin  --  lower-half tty device driver for output interrupts
 *------------------------------------------------------------------------
 */
void	ttyoin(struct tty *iptr)
{
    struct	csr	*cptr;
	int	ct;

	cptr = iptr->ioaddr;
	if (iptr->ehead	!= iptr->etail)	{
		cptr->ctbuf = iptr->ebuff[iptr->etail++];
		if (iptr->etail	>= EBUFLEN)
			iptr->etail = 0;
        cptr->ctstat = cptr->ctstat | SLUREADYON; // We have to "set the interrupt bit", because we don't have hardware to set it automatically.
		return;
	}
	if (iptr->oheld) {			/* honor flow control	*/
		cptr->ctstat = SLUDISABLE;
		return;
	}
	if ((ct=scount(iptr->osem)) < OBUFLEN) {
		cptr->ctbuf = iptr->obuff[iptr->otail++];
		if (iptr->otail	>= OBUFLEN)
            iptr->otail = 0;
		if (ct > OBMINSP)
			signal(iptr->osem);
		else if	( ++(iptr->odsend) == OBMINSP) {
			iptr->odsend = 0;
			signaln(iptr->osem, OBMINSP);
		}
        cptr->ctstat = cptr->ctstat | SLUREADYON; // We have to "set the interrupt bit", because we don't have hardware to set it automatically.
	} else
		cptr->ctstat = SLUDISABLE;
	return;
}
