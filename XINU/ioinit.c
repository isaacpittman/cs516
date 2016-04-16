/* ioinit.c - ioinit, iosetvec */

#include <conf.h>
#include <kernel.h>
#include <io.h>

/*------------------------------------------------------------------------
 *  ioinit --  standard interrupt vector and dispatch initialization
 *------------------------------------------------------------------------
 */
int ioinit(int descrp)
{
	int	minor;

	if (isbaddev(descrp) )
		return(SYSERR);
	minor = devtab[descrp].dvminor;
	iosetvec(descrp, minor, minor);
	return(OK);
}

/*------------------------------------------------------------------------
 *  iosetvec  -  fill in interrupt vectors and dispatch table entries
 *------------------------------------------------------------------------
 */
int iosetvec(int descrp, void *incode, void *outcode)
{
	struct	devsw	*devptr;
	struct	intmap	*map;
    //struct	vector	*vptr;

    struct sigaction sig_dispatch;
    sigset_t int_mask;

	if (isbaddev(descrp))
		return(SYSERR);
	devptr = &devtab[descrp];
	map = &intmap[devptr->dvnum];	/* fill in interrupt dispatch	*/
	map->iin =  devptr->dviint;	/*   map with addresses of high-*/
    map->icode = incode;		/*   level input and output	*/
	map->iout = devptr->dvoint;	/*   interrupt handlers and	*/
    map->ocode = outcode;		/*   minor device numbers	*/
/*	vptr = (struct vector *)devptr->dvivec;
    vptr->vproc = (char *)INTVECI;	// fill in input interrupt
    vptr->vps = descrp | DISABLE;	//   vector PC and PS values
	vptr = (struct vector *)devptr->dvovec;
    vptr->vproc = (char *)INTVECO;	// fill in output interrupt
    vptr->vps = descrp | DISABLE;	//   vector PC and PS values
    */
    /* Use signal handlers instead of vectors, since we don't have hardware vectors in Linux */
    sigfillset(&int_mask);
    sig_dispatch.sa_handler = ioint;
    sig_dispatch.sa_mask    = int_mask;
    sig_dispatch.sa_flags   = SA_RESTART;
    /* Our input/output "vectors" (really, signals) should call our dispatch function */
    if(sigaction(devptr->dvivec, &sig_dispatch, NULL) == -1) {
        exit(5);
    }
    if(sigaction(devptr->dvovec, &sig_dispatch, NULL) == -1) {
        exit(5);
    }
	return(OK);
}
