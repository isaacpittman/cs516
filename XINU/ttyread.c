/* ttyread.c - ttyread, readcopy */

#include <conf.h>
#include <kernel.h>
#include <tty.h>
#include <io.h>

LOCAL readcopy();

/*------------------------------------------------------------------------
 *  ttyread - read one or more characters from a tty device
 *------------------------------------------------------------------------
 */
int ttyread(struct devsw *devptr, char *buff, int count)
{
	char ps;
	register struct	tty *iptr;
	int avail, nread;

	if (count < 0)
		return(SYSERR);
	disable(ps);
	avail=scount((iptr= &tty[devptr->dvminor])->isem);

	if ((count = (count==0 ? avail : count)) == 0){
		restore(ps);
		return(0);
	}
	nread =	count;
	if (count <= avail) {
		readcopy(buff, iptr, count);
	} else {
		if (avail > 0) {
			readcopy(buff, iptr, avail);
			buff  += avail;
			count -= avail;
		}
		for ( ; count > 0 ; count--)
			*buff++ = ttygetc(devptr);
	}

	restore(ps);
	return(nread);
}

/*------------------------------------------------------------------------
 *  readcopy - high speed copy procedure used by ttyread
 *------------------------------------------------------------------------
 */
LOCAL readcopy(register char *buff, struct tty *iptr, int count)
{
         register char *qtail, *qend, *uend;    /* copy loop variables */

         qtail = &iptr->ibuff[iptr->itail];
         qend = &iptr->ibuff[IBUFLEN];
         uend = buff + count;
         while ( buff < uend ) {
                      *buff++ = *qtail++;
                      if ( qtail >= qend )
                            qtail = iptr->ibuff;
         }
         iptr->itail = qtail-iptr->ibuff;
         sreset(iptr->isem, scount(iptr->isem)-count);
	return;
}
