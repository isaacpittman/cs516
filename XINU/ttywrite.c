/* ttywrite.c - ttywrite, writcopy */

#include "conf.h"
#include "kernel.h"
#include "tty.h"
#include "io.h"
#include "slu.h"

LOCAL writcopy();

/*------------------------------------------------------------------------
 *  ttywrite - write one or more characters to a tty device
 *------------------------------------------------------------------------
 */
int ttywrite(struct devsw *devptr, char *buff, int count)
{
    struct tty *ttyp;
	int avail;
    sigset_t ps;

    if (count < 0)
		return(SYSERR);
	if (count == 0)
		return(OK);
	disable(ps);
	ttyp = &tty[devptr->dvminor];
        if ( (avail=scount(ttyp->osem)) >= count) {
                writcopy(buff, ttyp, count);
                (ttyp->ioaddr)->ctstat = SLUENABLE;
        }else{
                if (avail > 0) {
                        writcopy(buff, ttyp, avail);
                        buff  += avail;
                        count -= avail;
                        (ttyp->ioaddr)->ctstat = SLUENABLE;
                }
                for ( ; count>0 ; count--)
                        ttyputc(devptr, *buff++);

        }
	restore(ps);
	return(OK);
}

/*------------------------------------------------------------------------
 *  writcopy - high-speed copy from user's buffer into system buffer
 *------------------------------------------------------------------------
 */
LOCAL writcopy(char *buff, struct tty *ttyp, int count)
{
    char	*qhead, *qend, *uend;

         qhead = &ttyp->obuff[ttyp->ohead];
         qend = &ttyp->obuff[OBUFLEN];
         uend = buff + count;
         while ( buff < uend ) {
                 *qhead++ = *buff++;
                      if ( qhead >= qend )
                            qhead = ttyp->obuff;
         }
         ttyp->ohead = qhead - ttyp->obuff;
         sreset(ttyp->osem, scount(ttyp->osem)-count);
	return;
}
