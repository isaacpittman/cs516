/* io.h -  fgetc, fputc, getchar, isbaddev, putchar */


#define	INTVECI	inint		/* input interrupt dispatch routine	*/
#define	INTVECO	outint		/* output interrupt dispatch routine	*/
extern	int	INTVECI();
extern	int	INTVECO();
extern  void	ioint();

struct	intmap	{		/* device-to-interrupt routine mapping	*/
	void	(*iin)();	/* address of input interrupt routine	*/
	void	*icode;		/* argument passed to input routine	*/
	void	(*iout)();	/* address of output interrupt routine	*/
	void	*ocode;		/* argument passed to output routine	*/
};

#ifdef	NDEVS
extern	struct	intmap intmap[NDEVS];
#define	isbaddev(f)	( (f)<0 || (f)>=NDEVS )
#endif
#define	BADDEV		-1

/* In-line I/O procedures */

#define	getchar()	getc(CONSOLE)
#define	putchar(ch)	putc(CONSOLE,(ch))
#define	fgetc(unit)	getc((unit))
#define	fputc(unit,ch)	putc((unit),(ch))

struct	vector	{
	char	*vproc;		/* address of interrupt procedure	*/
	int	vps;		/* saved process status word		*/
};
