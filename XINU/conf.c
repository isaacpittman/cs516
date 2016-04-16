/* conf.c (GENERATED FILE; DO NOT EDIT) */

#include <conf.h>

/* device independent I/O switch */

struct	devsw	devtab[NDEVS] = {

/*  Format of entries is:
device-number, 
init, open, close,
read, write, seek,
getc, putc, cntl,
device-csr-address, input-vector, output-vector,
iint-handler, oint-handler, control-block, minor-device,
*/

/*  CONSOLE  is tty  */

0, 
ttyinit, ttyopen, ionull,
ttyread, ttywrite, ioerr,
ttygetc, ttyputc, ttycntl,
0177560, 0060, 0064,
ttyiin, ttyoin, NULLPTR, 0,

/*  OTHER  is tty  */

1,
ttyinit, ttyopen, ionull,
ttyread, ttywrite, ioerr,
ttygetc, ttyputc, ttycntl,
0176500, 0300, 0304,
ttyiin, ttyoin, NULLPTR, 1,

/*  RING0IN  is dlc  */

2, 
dlcinit, ioerr, ioerr,
dlcread, dlcwrite, ioerr,
ioerr, dlcputc, dlccntl,
0176510, 0310, 0314,
dlciin, dlcoin, NULLPTR, 0,

/*  RING0OUT  is dlc  */

3, 
dlcinit, ioerr, ioerr,
dlcread, dlcwrite, ioerr,
ioerr, dlcputc, dlccntl,
0176520, 0320, 0324,
dlciin, dlcoin, NULLPTR, 1,

/*  DISK0   is  ds  */

4,
dsinit, dsopen, ioerr,
dsread, dswrite, dsseek,
ioerr, ioerr, dscntl,
0177460, 0134, 0134,
dsinter, dsinter, NULLPTR, 0,

/*  FILE1  is lf  */

5, 
lfinit, ioerr, lfclose,
lfread, lfwrite, lfseek,
lfgetc, lfputc, ioerr,
0000000, 0000, 0000,
ioerr, ioerr, NULLPTR, 0,

/*  FILE2  is lf  */

6, 
lfinit, ioerr, lfclose,
lfread, lfwrite, lfseek,
lfgetc, lfputc, ioerr,
0000000, 0000, 0000,
ioerr, ioerr, NULLPTR, 1,
/*  FILE3  is lf  */

7, 
lfinit, ioerr, lfclose,
lfread, lfwrite, lfseek,
lfgetc, lfputc, ioerr,
0000000, 0000, 0000,
ioerr, ioerr, NULLPTR, 2,

/*  FILE4  is lf  */

8,
lfinit, ioerr, lfclose,
lfread, lfwrite, lfseek,
lfgetc, lfputc, ioerr,
0000000, 0000, 0000,
ioerr, ioerr, NULLPTR, 3,
	};
