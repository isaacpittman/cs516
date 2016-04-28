/* ttycntl.c - ttycntl */

#include "conf.h"
#include "kernel.h"
#include "tty.h"
#include "io.h"
#include "slu.h"

/*------------------------------------------------------------------------
 *  ttycntl  -  control a tty device by setting modes
 *------------------------------------------------------------------------
 */
int ttycntl(struct devsw *devptr, int func, char *addr)
{
    struct	tty *ttyp;
	char	ch;
    sigset_t	ps;

	ttyp = &tty[devptr->dvminor];
	switch ( func )	{
	case TCSETBRK:
		ttyp->ioaddr->ctstat |=	SLUTBREAK;
		break;
	case TCRSTBRK:
		ttyp->ioaddr->ctstat &=	~SLUTBREAK;
		break;
	case TCNEXTC:
		disable(ps);
		wait(ttyp->isem);
		ch = ttyp->ibuff[ttyp->itail];
		restore(ps);
		signal(ttyp->isem);
		return(ch);
	case TCMODER:
		ttyp->imode = IMRAW;
		break;
	case TCMODEC:
		ttyp->imode = IMCOOKED;
		break;
	case TCMODEK:
		ttyp->imode = IMCBREAK;
		break;
	case TCECHO:
		ttyp->iecho = TRUE;
		break;
	case TCNOECHO:
		ttyp->iecho = FALSE;
		break;
	case TCICHARS:
		return(scount(ttyp->isem));
	default:
		return(SYSERR);
	}
	return(OK);
}
