/* conf.c (GENERATED FILE; DO NOT EDIT) */

#include "conf.h"

#define SIGUSR1 (10)
#define SIGUSR2 (12)

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
NULLPTR, SIGUSR1, SIGUSR2,
ttyiin, ttyoin, NULLPTR, 0,
	};
