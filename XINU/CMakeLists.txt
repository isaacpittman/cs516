project(XINU)
cmake_minimum_required(VERSION 2.8)
add_executable(${PROJECT_NAME} cli.h conf.h kernel.h signal.h sleep.h conf.h proc.h mem.h io.h q.h sem.h chprio.c clkinit.c clkint.c create.c ctxsw.c freemem.c getitem.c getmem.c getpid.c getprio.c getstk.c initialize.c insert.c insertd.c kill.c newqueue.c queue.c ready.c receive.c recvclr.c resched.c resume.c screate.c sdelete.c send.c signal.c sleep10.c sleep.c ssclock.c suspend.c userret.c wait.c wakeup.c)
