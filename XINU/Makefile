CC = gcc
CFLAGS = -g -c
CXX_CFLAGS = -I. -I/usr/lib/gcc/i686-redhat-linux/4.4.4/include
LDFLAGS=
SOURCES = chprio.c clkinit.c clkint.c create.c ctxsw.c freemem.c getitem.c getmem.c \
getpid.c getprio.c getstk.c initialize.c insert.c insertd.c kill.c newqueue.c queue.c \
ready.c receive.c recvclr.c resched.c resume.c screate.c sdelete.c send.c signal.c \
sleep10.c sleep.c ssclock.c suspend.c userret.c wait.c wakeup.c cli.c lex.yy.c \
ttyiin.c ttyoin.c ttyinit.c ttyopen.c ttyputc.c ttyread.c ttywrite.c \
ttycntl.c ttygetc.c ioinit.c ioint.c conf.c close.c ioerr.c ionull.c open.c \
putc.c seek.c write.c control.c getc.c read.c signaln.c scount.c sreset.c init.c 
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = xinu.exe


all: $(SOURCES) $(EXECUTABLE)

	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@ $(CXX_CFLAGS)
clean:
	rm -f *.o $(EXECUTABLE)

depend:
	makedepend --$(CFLAGS) --$(SOURCES) -I. -I/usr/lib/gcc/i686-redhat-linux/4.4.4/include
