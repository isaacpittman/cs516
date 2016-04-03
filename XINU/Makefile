CC = gcc
CFLAGS = -g -c -I. -I/usr/lib/gcc/i686-redhat-linux/4.4.4/include
CXX_CFLAGS = -I.
LDFLAGS=
SOURCES = chprio.c clkinit.c clkint.c create.c ctxsw.c freemem.c getitem.c getmem.c \
getpid.c getprio.c getstk.c initialize.c insert.c insertd.c kill.c newqueue.c queue.c \
ready.c receive.c recvclr.c resched.c resume.c screate.c sdelete.c send.c signal.c \
sleep10.c sleep.c ssclock.c suspend.c userret.c wait.c wakeup.c cli.c lex.yy.c
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
	makedepend --$(CFLAGS) --$(SOURCES)
# DO NOT DELETE

clkinit.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
clkinit.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
clkinit.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
clkinit.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
clkinit.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
clkinit.o: /usr/include/time.h /usr/include/bits/siginfo.h
clkinit.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
clkinit.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
clkinit.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
clkinit.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
clkinit.o: /usr/include/asm-generic/bitsperlong.h
clkinit.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
clkinit.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
clkinit.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
clkinit.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
clkinit.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
clkinit.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
clkinit.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
clkinit.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
clkinit.o: /usr/include/sys/time.h /usr/include/bits/time.h
clkinit.o: /usr/include/sys/select.h /usr/include/bits/select.h
clkinit.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
clkinit.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
clkinit.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
clkinit.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
clkinit.o: /usr/include/alloca.h /usr/include/ucontext.h
clkinit.o: /usr/include/sys/ucontext.h ./sleep.h
clkint.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
clkint.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
clkint.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
clkint.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
clkint.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
clkint.o: /usr/include/time.h /usr/include/bits/siginfo.h
clkint.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
clkint.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
clkint.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
clkint.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
clkint.o: /usr/include/asm-generic/bitsperlong.h
clkint.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
clkint.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
clkint.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
clkint.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
clkint.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
clkint.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
clkint.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
clkint.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
clkint.o: /usr/include/sys/time.h /usr/include/bits/time.h
clkint.o: /usr/include/sys/select.h /usr/include/bits/select.h
clkint.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
clkint.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
clkint.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
clkint.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
clkint.o: /usr/include/alloca.h /usr/include/ucontext.h
clkint.o: /usr/include/sys/ucontext.h ./proc.h ./mem.h ./sleep.h
create.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
create.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
create.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
create.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
create.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
create.o: /usr/include/time.h /usr/include/bits/siginfo.h
create.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
create.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
create.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
create.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
create.o: /usr/include/asm-generic/bitsperlong.h
create.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
create.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
create.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
create.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
create.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
create.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
create.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
create.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
create.o: /usr/include/sys/time.h /usr/include/bits/time.h
create.o: /usr/include/sys/select.h /usr/include/bits/select.h
create.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
create.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
create.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
create.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
create.o: /usr/include/alloca.h /usr/include/ucontext.h
create.o: /usr/include/sys/ucontext.h ./proc.h ./mem.h ./io.h
ctxsw.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
ctxsw.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ctxsw.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
ctxsw.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
ctxsw.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
ctxsw.o: /usr/include/time.h /usr/include/bits/siginfo.h
ctxsw.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
ctxsw.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
ctxsw.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
ctxsw.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
ctxsw.o: /usr/include/asm-generic/bitsperlong.h
ctxsw.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
ctxsw.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
ctxsw.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
ctxsw.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
ctxsw.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
ctxsw.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
ctxsw.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
ctxsw.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ctxsw.o: /usr/include/sys/time.h /usr/include/bits/time.h
ctxsw.o: /usr/include/sys/select.h /usr/include/bits/select.h
ctxsw.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
ctxsw.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
ctxsw.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
ctxsw.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
ctxsw.o: /usr/include/alloca.h /usr/include/ucontext.h
ctxsw.o: /usr/include/sys/ucontext.h ./proc.h ./mem.h ./io.h
freemem.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
freemem.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
freemem.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
freemem.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
freemem.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
freemem.o: /usr/include/time.h /usr/include/bits/siginfo.h
freemem.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
freemem.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
freemem.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
freemem.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
freemem.o: /usr/include/asm-generic/bitsperlong.h
freemem.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
freemem.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
freemem.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
freemem.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
freemem.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
freemem.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
freemem.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
freemem.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
freemem.o: /usr/include/sys/time.h /usr/include/bits/time.h
freemem.o: /usr/include/sys/select.h /usr/include/bits/select.h
freemem.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
freemem.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
freemem.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
freemem.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
freemem.o: /usr/include/alloca.h /usr/include/ucontext.h
freemem.o: /usr/include/sys/ucontext.h ./mem.h
getitem.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
getitem.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
getitem.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
getitem.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
getitem.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
getitem.o: /usr/include/time.h /usr/include/bits/siginfo.h
getitem.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
getitem.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
getitem.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
getitem.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
getitem.o: /usr/include/asm-generic/bitsperlong.h
getitem.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
getitem.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
getitem.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
getitem.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
getitem.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
getitem.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
getitem.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
getitem.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getitem.o: /usr/include/sys/time.h /usr/include/bits/time.h
getitem.o: /usr/include/sys/select.h /usr/include/bits/select.h
getitem.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
getitem.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
getitem.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
getitem.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
getitem.o: /usr/include/alloca.h /usr/include/ucontext.h
getitem.o: /usr/include/sys/ucontext.h ./q.h
getmem.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
getmem.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
getmem.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
getmem.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
getmem.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
getmem.o: /usr/include/time.h /usr/include/bits/siginfo.h
getmem.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
getmem.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
getmem.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
getmem.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
getmem.o: /usr/include/asm-generic/bitsperlong.h
getmem.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
getmem.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
getmem.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
getmem.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
getmem.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
getmem.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
getmem.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
getmem.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getmem.o: /usr/include/sys/time.h /usr/include/bits/time.h
getmem.o: /usr/include/sys/select.h /usr/include/bits/select.h
getmem.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
getmem.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
getmem.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
getmem.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
getmem.o: /usr/include/alloca.h /usr/include/ucontext.h
getmem.o: /usr/include/sys/ucontext.h ./mem.h
getpid.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
getpid.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
getpid.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
getpid.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
getpid.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
getpid.o: /usr/include/time.h /usr/include/bits/siginfo.h
getpid.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
getpid.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
getpid.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
getpid.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
getpid.o: /usr/include/asm-generic/bitsperlong.h
getpid.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
getpid.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
getpid.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
getpid.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
getpid.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
getpid.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
getpid.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
getpid.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getpid.o: /usr/include/sys/time.h /usr/include/bits/time.h
getpid.o: /usr/include/sys/select.h /usr/include/bits/select.h
getpid.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
getpid.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
getpid.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
getpid.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
getpid.o: /usr/include/alloca.h /usr/include/ucontext.h
getpid.o: /usr/include/sys/ucontext.h ./proc.h
getprio.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
getprio.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
getprio.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
getprio.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
getprio.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
getprio.o: /usr/include/time.h /usr/include/bits/siginfo.h
getprio.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
getprio.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
getprio.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
getprio.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
getprio.o: /usr/include/asm-generic/bitsperlong.h
getprio.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
getprio.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
getprio.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
getprio.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
getprio.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
getprio.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
getprio.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
getprio.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getprio.o: /usr/include/sys/time.h /usr/include/bits/time.h
getprio.o: /usr/include/sys/select.h /usr/include/bits/select.h
getprio.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
getprio.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
getprio.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
getprio.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
getprio.o: /usr/include/alloca.h /usr/include/ucontext.h
getprio.o: /usr/include/sys/ucontext.h ./proc.h
getstk.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
getstk.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
getstk.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
getstk.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
getstk.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
getstk.o: /usr/include/time.h /usr/include/bits/siginfo.h
getstk.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
getstk.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
getstk.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
getstk.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
getstk.o: /usr/include/asm-generic/bitsperlong.h
getstk.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
getstk.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
getstk.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
getstk.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
getstk.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
getstk.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
getstk.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
getstk.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getstk.o: /usr/include/sys/time.h /usr/include/bits/time.h
getstk.o: /usr/include/sys/select.h /usr/include/bits/select.h
getstk.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
getstk.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
getstk.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
getstk.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
getstk.o: /usr/include/alloca.h /usr/include/ucontext.h
getstk.o: /usr/include/sys/ucontext.h ./mem.h
initialize.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
initialize.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
initialize.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
initialize.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
initialize.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
initialize.o: /usr/include/time.h /usr/include/bits/siginfo.h
initialize.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
initialize.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
initialize.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
initialize.o: /usr/include/asm-generic/int-ll64.h
initialize.o: /usr/include/asm/bitsperlong.h
initialize.o: /usr/include/asm-generic/bitsperlong.h
initialize.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
initialize.o: /usr/include/asm/posix_types.h
initialize.o: /usr/include/asm/posix_types_32.h
initialize.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
initialize.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
initialize.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
initialize.o: /usr/include/libio.h /usr/include/_G_config.h
initialize.o: /usr/include/wchar.h
initialize.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
initialize.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
initialize.o: /usr/include/sys/time.h /usr/include/bits/time.h
initialize.o: /usr/include/sys/select.h /usr/include/bits/select.h
initialize.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
initialize.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
initialize.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
initialize.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
initialize.o: /usr/include/alloca.h /usr/include/ucontext.h
initialize.o: /usr/include/sys/ucontext.h ./proc.h ./sem.h ./sleep.h ./mem.h
initialize.o: ./q.h ./io.h
insert.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
insert.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
insert.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
insert.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
insert.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
insert.o: /usr/include/time.h /usr/include/bits/siginfo.h
insert.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
insert.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
insert.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
insert.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
insert.o: /usr/include/asm-generic/bitsperlong.h
insert.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
insert.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
insert.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
insert.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
insert.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
insert.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
insert.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
insert.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
insert.o: /usr/include/sys/time.h /usr/include/bits/time.h
insert.o: /usr/include/sys/select.h /usr/include/bits/select.h
insert.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
insert.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
insert.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
insert.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
insert.o: /usr/include/alloca.h /usr/include/ucontext.h
insert.o: /usr/include/sys/ucontext.h ./q.h
insertd.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
insertd.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
insertd.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
insertd.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
insertd.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
insertd.o: /usr/include/time.h /usr/include/bits/siginfo.h
insertd.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
insertd.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
insertd.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
insertd.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
insertd.o: /usr/include/asm-generic/bitsperlong.h
insertd.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
insertd.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
insertd.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
insertd.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
insertd.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
insertd.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
insertd.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
insertd.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
insertd.o: /usr/include/sys/time.h /usr/include/bits/time.h
insertd.o: /usr/include/sys/select.h /usr/include/bits/select.h
insertd.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
insertd.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
insertd.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
insertd.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
insertd.o: /usr/include/alloca.h /usr/include/ucontext.h
insertd.o: /usr/include/sys/ucontext.h ./q.h
kill.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
kill.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
kill.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
kill.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
kill.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
kill.o: /usr/include/time.h /usr/include/bits/siginfo.h
kill.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
kill.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
kill.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
kill.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
kill.o: /usr/include/asm-generic/bitsperlong.h
kill.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
kill.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
kill.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
kill.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
kill.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
kill.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
kill.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
kill.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
kill.o: /usr/include/sys/time.h /usr/include/bits/time.h
kill.o: /usr/include/sys/select.h /usr/include/bits/select.h
kill.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
kill.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
kill.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
kill.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
kill.o: /usr/include/alloca.h /usr/include/ucontext.h
kill.o: /usr/include/sys/ucontext.h ./proc.h ./sem.h ./mem.h ./io.h
newqueue.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
newqueue.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
newqueue.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
newqueue.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
newqueue.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
newqueue.o: /usr/include/time.h /usr/include/bits/siginfo.h
newqueue.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
newqueue.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
newqueue.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
newqueue.o: /usr/include/asm-generic/int-ll64.h
newqueue.o: /usr/include/asm/bitsperlong.h
newqueue.o: /usr/include/asm-generic/bitsperlong.h
newqueue.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
newqueue.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
newqueue.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
newqueue.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
newqueue.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
newqueue.o: /usr/include/libio.h /usr/include/_G_config.h
newqueue.o: /usr/include/wchar.h
newqueue.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
newqueue.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
newqueue.o: /usr/include/sys/time.h /usr/include/bits/time.h
newqueue.o: /usr/include/sys/select.h /usr/include/bits/select.h
newqueue.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
newqueue.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
newqueue.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
newqueue.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
newqueue.o: /usr/include/alloca.h /usr/include/ucontext.h
newqueue.o: /usr/include/sys/ucontext.h ./q.h
queue.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
queue.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
queue.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
queue.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
queue.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
queue.o: /usr/include/time.h /usr/include/bits/siginfo.h
queue.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
queue.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
queue.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
queue.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
queue.o: /usr/include/asm-generic/bitsperlong.h
queue.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
queue.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
queue.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
queue.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
queue.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
queue.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
queue.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
queue.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
queue.o: /usr/include/sys/time.h /usr/include/bits/time.h
queue.o: /usr/include/sys/select.h /usr/include/bits/select.h
queue.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
queue.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
queue.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
queue.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
queue.o: /usr/include/alloca.h /usr/include/ucontext.h
queue.o: /usr/include/sys/ucontext.h ./q.h
ready.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
ready.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ready.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
ready.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
ready.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
ready.o: /usr/include/time.h /usr/include/bits/siginfo.h
ready.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
ready.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
ready.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
ready.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
ready.o: /usr/include/asm-generic/bitsperlong.h
ready.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
ready.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
ready.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
ready.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
ready.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
ready.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
ready.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
ready.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ready.o: /usr/include/sys/time.h /usr/include/bits/time.h
ready.o: /usr/include/sys/select.h /usr/include/bits/select.h
ready.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
ready.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
ready.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
ready.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
ready.o: /usr/include/alloca.h /usr/include/ucontext.h
ready.o: /usr/include/sys/ucontext.h ./proc.h ./q.h
receive.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
receive.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
receive.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
receive.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
receive.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
receive.o: /usr/include/time.h /usr/include/bits/siginfo.h
receive.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
receive.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
receive.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
receive.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
receive.o: /usr/include/asm-generic/bitsperlong.h
receive.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
receive.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
receive.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
receive.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
receive.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
receive.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
receive.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
receive.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
receive.o: /usr/include/sys/time.h /usr/include/bits/time.h
receive.o: /usr/include/sys/select.h /usr/include/bits/select.h
receive.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
receive.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
receive.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
receive.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
receive.o: /usr/include/alloca.h /usr/include/ucontext.h
receive.o: /usr/include/sys/ucontext.h ./proc.h
recvclr.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
recvclr.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
recvclr.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
recvclr.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
recvclr.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
recvclr.o: /usr/include/time.h /usr/include/bits/siginfo.h
recvclr.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
recvclr.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
recvclr.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
recvclr.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
recvclr.o: /usr/include/asm-generic/bitsperlong.h
recvclr.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
recvclr.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
recvclr.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
recvclr.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
recvclr.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
recvclr.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
recvclr.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
recvclr.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
recvclr.o: /usr/include/sys/time.h /usr/include/bits/time.h
recvclr.o: /usr/include/sys/select.h /usr/include/bits/select.h
recvclr.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
recvclr.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
recvclr.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
recvclr.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
recvclr.o: /usr/include/alloca.h /usr/include/ucontext.h
recvclr.o: /usr/include/sys/ucontext.h ./proc.h
resched.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
resched.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
resched.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
resched.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
resched.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
resched.o: /usr/include/time.h /usr/include/bits/siginfo.h
resched.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
resched.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
resched.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
resched.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
resched.o: /usr/include/asm-generic/bitsperlong.h
resched.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
resched.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
resched.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
resched.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
resched.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
resched.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
resched.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
resched.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
resched.o: /usr/include/sys/time.h /usr/include/bits/time.h
resched.o: /usr/include/sys/select.h /usr/include/bits/select.h
resched.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
resched.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
resched.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
resched.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
resched.o: /usr/include/alloca.h /usr/include/ucontext.h
resched.o: /usr/include/sys/ucontext.h ./proc.h ./q.h
resume.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
resume.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
resume.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
resume.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
resume.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
resume.o: /usr/include/time.h /usr/include/bits/siginfo.h
resume.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
resume.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
resume.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
resume.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
resume.o: /usr/include/asm-generic/bitsperlong.h
resume.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
resume.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
resume.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
resume.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
resume.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
resume.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
resume.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
resume.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
resume.o: /usr/include/sys/time.h /usr/include/bits/time.h
resume.o: /usr/include/sys/select.h /usr/include/bits/select.h
resume.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
resume.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
resume.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
resume.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
resume.o: /usr/include/alloca.h /usr/include/ucontext.h
resume.o: /usr/include/sys/ucontext.h ./proc.h
screate.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
screate.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
screate.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
screate.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
screate.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
screate.o: /usr/include/time.h /usr/include/bits/siginfo.h
screate.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
screate.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
screate.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
screate.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
screate.o: /usr/include/asm-generic/bitsperlong.h
screate.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
screate.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
screate.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
screate.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
screate.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
screate.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
screate.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
screate.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
screate.o: /usr/include/sys/time.h /usr/include/bits/time.h
screate.o: /usr/include/sys/select.h /usr/include/bits/select.h
screate.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
screate.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
screate.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
screate.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
screate.o: /usr/include/alloca.h /usr/include/ucontext.h
screate.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sem.h
sdelete.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
sdelete.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
sdelete.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
sdelete.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
sdelete.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
sdelete.o: /usr/include/time.h /usr/include/bits/siginfo.h
sdelete.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
sdelete.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
sdelete.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
sdelete.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
sdelete.o: /usr/include/asm-generic/bitsperlong.h
sdelete.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
sdelete.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
sdelete.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
sdelete.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
sdelete.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
sdelete.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
sdelete.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
sdelete.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
sdelete.o: /usr/include/sys/time.h /usr/include/bits/time.h
sdelete.o: /usr/include/sys/select.h /usr/include/bits/select.h
sdelete.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
sdelete.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
sdelete.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
sdelete.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
sdelete.o: /usr/include/alloca.h /usr/include/ucontext.h
sdelete.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sem.h
send.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
send.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
send.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
send.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
send.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
send.o: /usr/include/time.h /usr/include/bits/siginfo.h
send.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
send.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
send.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
send.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
send.o: /usr/include/asm-generic/bitsperlong.h
send.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
send.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
send.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
send.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
send.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
send.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
send.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
send.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
send.o: /usr/include/sys/time.h /usr/include/bits/time.h
send.o: /usr/include/sys/select.h /usr/include/bits/select.h
send.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
send.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
send.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
send.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
send.o: /usr/include/alloca.h /usr/include/ucontext.h
send.o: /usr/include/sys/ucontext.h ./proc.h
signal.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
signal.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
signal.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
signal.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
signal.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
signal.o: /usr/include/time.h /usr/include/bits/siginfo.h
signal.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
signal.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
signal.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
signal.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
signal.o: /usr/include/asm-generic/bitsperlong.h
signal.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
signal.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
signal.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
signal.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
signal.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
signal.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
signal.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
signal.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
signal.o: /usr/include/sys/time.h /usr/include/bits/time.h
signal.o: /usr/include/sys/select.h /usr/include/bits/select.h
signal.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
signal.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
signal.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
signal.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
signal.o: /usr/include/alloca.h /usr/include/ucontext.h
signal.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sem.h
sleep10.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
sleep10.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
sleep10.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
sleep10.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
sleep10.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
sleep10.o: /usr/include/time.h /usr/include/bits/siginfo.h
sleep10.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
sleep10.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
sleep10.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
sleep10.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
sleep10.o: /usr/include/asm-generic/bitsperlong.h
sleep10.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
sleep10.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
sleep10.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
sleep10.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
sleep10.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
sleep10.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
sleep10.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
sleep10.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
sleep10.o: /usr/include/sys/time.h /usr/include/bits/time.h
sleep10.o: /usr/include/sys/select.h /usr/include/bits/select.h
sleep10.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
sleep10.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
sleep10.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
sleep10.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
sleep10.o: /usr/include/alloca.h /usr/include/ucontext.h
sleep10.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sleep.h
sleep.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
sleep.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
sleep.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
sleep.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
sleep.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
sleep.o: /usr/include/time.h /usr/include/bits/siginfo.h
sleep.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
sleep.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
sleep.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
sleep.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
sleep.o: /usr/include/asm-generic/bitsperlong.h
sleep.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
sleep.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
sleep.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
sleep.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
sleep.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
sleep.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
sleep.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
sleep.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
sleep.o: /usr/include/sys/time.h /usr/include/bits/time.h
sleep.o: /usr/include/sys/select.h /usr/include/bits/select.h
sleep.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
sleep.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
sleep.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
sleep.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
sleep.o: /usr/include/alloca.h /usr/include/ucontext.h
sleep.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sleep.h
ssclock.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
ssclock.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ssclock.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
ssclock.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
ssclock.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
ssclock.o: /usr/include/time.h /usr/include/bits/siginfo.h
ssclock.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
ssclock.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
ssclock.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
ssclock.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
ssclock.o: /usr/include/asm-generic/bitsperlong.h
ssclock.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
ssclock.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
ssclock.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
ssclock.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
ssclock.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
ssclock.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
ssclock.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
ssclock.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ssclock.o: /usr/include/sys/time.h /usr/include/bits/time.h
ssclock.o: /usr/include/sys/select.h /usr/include/bits/select.h
ssclock.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
ssclock.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
ssclock.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
ssclock.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
ssclock.o: /usr/include/alloca.h /usr/include/ucontext.h
ssclock.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sleep.h
suspend.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
suspend.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
suspend.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
suspend.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
suspend.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
suspend.o: /usr/include/time.h /usr/include/bits/siginfo.h
suspend.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
suspend.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
suspend.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
suspend.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
suspend.o: /usr/include/asm-generic/bitsperlong.h
suspend.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
suspend.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
suspend.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
suspend.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
suspend.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
suspend.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
suspend.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
suspend.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
suspend.o: /usr/include/sys/time.h /usr/include/bits/time.h
suspend.o: /usr/include/sys/select.h /usr/include/bits/select.h
suspend.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
suspend.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
suspend.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
suspend.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
suspend.o: /usr/include/alloca.h /usr/include/ucontext.h
suspend.o: /usr/include/sys/ucontext.h ./proc.h
userret.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
userret.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
userret.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
userret.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
userret.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
userret.o: /usr/include/time.h /usr/include/bits/siginfo.h
userret.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
userret.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
userret.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
userret.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
userret.o: /usr/include/asm-generic/bitsperlong.h
userret.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
userret.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
userret.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
userret.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
userret.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
userret.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
userret.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
userret.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
userret.o: /usr/include/sys/time.h /usr/include/bits/time.h
userret.o: /usr/include/sys/select.h /usr/include/bits/select.h
userret.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
userret.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
userret.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
userret.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
userret.o: /usr/include/alloca.h /usr/include/ucontext.h
userret.o: /usr/include/sys/ucontext.h
wait.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
wait.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
wait.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
wait.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
wait.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
wait.o: /usr/include/time.h /usr/include/bits/siginfo.h
wait.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
wait.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
wait.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
wait.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
wait.o: /usr/include/asm-generic/bitsperlong.h
wait.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
wait.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
wait.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
wait.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
wait.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
wait.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
wait.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
wait.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
wait.o: /usr/include/sys/time.h /usr/include/bits/time.h
wait.o: /usr/include/sys/select.h /usr/include/bits/select.h
wait.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
wait.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
wait.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
wait.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
wait.o: /usr/include/alloca.h /usr/include/ucontext.h
wait.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sem.h
wakeup.o: ./conf.h ./kernel.h ./signal.h /usr/include/features.h
wakeup.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
wakeup.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
wakeup.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
wakeup.o: /usr/include/bits/typesizes.h /usr/include/bits/signum.h
wakeup.o: /usr/include/time.h /usr/include/bits/siginfo.h
wakeup.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
wakeup.o: /usr/include/asm/sigcontext.h /usr/include/linux/types.h
wakeup.o: /usr/include/asm/types.h /usr/include/asm-generic/types.h
wakeup.o: /usr/include/asm-generic/int-ll64.h /usr/include/asm/bitsperlong.h
wakeup.o: /usr/include/asm-generic/bitsperlong.h
wakeup.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
wakeup.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h
wakeup.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stddef.h
wakeup.o: /usr/include/bits/sigstack.h /usr/include/bits/pthreadtypes.h
wakeup.o: /usr/include/bits/sigthread.h /usr/include/stdio.h
wakeup.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
wakeup.o: /usr/lib/gcc/i686-redhat-linux/4.4.4/include/stdarg.h
wakeup.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
wakeup.o: /usr/include/sys/time.h /usr/include/bits/time.h
wakeup.o: /usr/include/sys/select.h /usr/include/bits/select.h
wakeup.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
wakeup.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
wakeup.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
wakeup.o: /usr/include/sys/types.h /usr/include/sys/sysmacros.h
wakeup.o: /usr/include/alloca.h /usr/include/ucontext.h
wakeup.o: /usr/include/sys/ucontext.h ./proc.h ./q.h ./sleep.h
