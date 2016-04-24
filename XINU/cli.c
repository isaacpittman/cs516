#include "cli.h"
#include "conf.h"
#include "kernel.h"
#include "proc.h"
#include "q.h"
#include "sleep.h"

/* Declarations to work with flex */
extern  int     yylex();            /* the lexical analyzer for our command line interpreter (created by the flex tool) */
        int     yylval;             /* the value associated with some token returned by the lexical analyzer */
extern  void    prompt();           /* Display the command line interpreter's prompt */

/* Helper functions */
void    itoa(int n, char *s);      /* convert integer to ascii string */
void    reverse(char s[]);          /* reverse a string. used by itoa. */

/* CLI functions */
void    show_proc();
void    show_slp();
void    show_rdy();
void    create_slp();
void    do_kill(int);
void    do_resume(int);
void    do_suspend(int);
void    create_rcv();
void    create_wtr();
void    create_sig();
void    create_snd();
void    create_rdy();

/* Dummy processes */
void    slp_func();
void    rcv_func();
void    wtr_func();
void    sig_func();
void    snd_func();
void    rdy_func();

int     sem             = -1; /* Semaphore for wtr_func and sig_func */
int     rcv_func_pid    = -1; /* Receiver pid for rcv_func and snd_func */
int     token;
int     value;
char    exit_msg[]          = "\tCOMMAND LINE INTERPRETER IS DONE, GOODBYE\n";

void start_cli() {
    prompt();

    while((token = yylex()) != TKN_EXIT) {

        switch (token) {
        case TKN_RESUME:
            value = yylval;
            do_resume(value);
            break;
        case TKN_KILL:
            value = yylval;
            do_kill(value);
            break;
        case TKN_SHOW_PROC:
            show_proc();
            break;
        case TKN_SHOW_SLP:
            show_slp();
            break;
        case TKN_SHOW_RDY:
            show_rdy();
            break;
        case TKN_CREATE_SLP:
            create_slp();
            break;
        case TKN_CREATE_RCV:
            create_rcv();
            break;
        case TKN_CREATE_WTR:
            create_wtr();
            break;
        case TKN_CREATE_SIG:
            create_sig();
            break;
        case TKN_CREATE_SND:
            create_snd();
            break;
        case TKN_CREATE_RDY:
            create_rdy();
            break;
        case TKN_SUSPEND:
            value = yylval;
            do_suspend(value);
            break;
        }
    }

    write(CONSOLE, exit_msg, sizeof(exit_msg)-1);
}

void create_rdy(){
    char create_rdy_msg[]    = "\tIN CREATE WITH RDY\n";
    write(CONSOLE, create_rdy_msg, sizeof(create_rdy_msg)-1);

    int rdy_func_pid;
    if((rdy_func_pid = create(rdy_func, MINSTK, 20, "RDY", 1, 0)) == SYSERR){
        write(CONSOLE, "\ncreate rdy_func failed\n", 24);
    }
}

void rdy_func(){
    char rdy_proc_alive_msg[] = "\nRDY process is alive with pid N\n";
    char rdy_will_spin_msg[] = "\nRDY will spin forever\n";

    rdy_proc_alive_msg[31] = (getpid() + 48);
    write(CONSOLE, rdy_proc_alive_msg, sizeof(rdy_proc_alive_msg)-1);

    write(CONSOLE, rdy_will_spin_msg, sizeof(rdy_will_spin_msg)-1);

    while (1);
}

void create_sig(){
    char create_sig_msg[]    = "\tIN CREATE WITH SIG\n";
    write(CONSOLE, create_sig_msg, sizeof(create_sig_msg)-1);

    int sig_func_pid;
    if((sig_func_pid = create(sig_func, MINSTK, 20, "SIG", 1, 0)) == SYSERR){
        write(CONSOLE, "\ncreate sig_func failed\n", 24);
    }
}

void sig_func(){
    char sig_proc_alive_msg[] = "\nSIG process is alive with pid N\n";
    char sig_sent_signal_msg[] = "\nSIG sent signal\n";

    sig_proc_alive_msg[31] = (getpid() + 48);
    write(CONSOLE, sig_proc_alive_msg, sizeof(sig_proc_alive_msg)-1);

    if (sem==-1){
        if((sem = screate(0)) == SYSERR){
            write(CONSOLE, "\nsem create failed\n", 19);
        }
    }

    if(signal(sem) == SYSERR){
        write(CONSOLE, "\nin sig_func signal failed\n", 27);
    }

    write(CONSOLE, sig_sent_signal_msg, sizeof(sig_sent_signal_msg)-1);
}

void create_snd(){
    char create_snd_msg[]    = "\tIN CREATE WITH SND\n";
    write(CONSOLE, create_snd_msg, sizeof(create_snd_msg)-1);

    int snd_func_pid;
    if((snd_func_pid = create(snd_func, MINSTK, 20, "SND", 1, 0)) == SYSERR){
        write(CONSOLE, "\ncreate snd_func failed\n", 24);
    }
}

void snd_func(){
    char snd_proc_alive_msg[] = "\nSND process is alive with pid N\n";
    char snd_sent_message_msg[] = "\nSND sent message\n";

    snd_proc_alive_msg[31] = (getpid() + 48);
    write(CONSOLE, snd_proc_alive_msg, sizeof(snd_proc_alive_msg)-1);

    if(send(rcv_func_pid, 999) == SYSERR){
        write(CONSOLE, "\nin snd_func send failed\n", 25);
    }

    write(CONSOLE, snd_sent_message_msg, sizeof(snd_sent_message_msg)-1);
}

void create_wtr(){
    char create_wtr_msg[]    = "\tIN CREATE WITH WTR\n";
    write(CONSOLE, create_wtr_msg, sizeof(create_wtr_msg)-1);

    int wtr_func_pid;
    if((wtr_func_pid = create(wtr_func, MINSTK, 20, "WTR", 1, 0)) == SYSERR){
        write(CONSOLE, "\ncreate wtr_func failed\n", 24);
    }
}

void wtr_func(){
    char wtr_proc_alive_msg[] = "\nWTR process is alive with pid N\n";
    char wtr_got_signal_msg[] = "\nWTR received signal\n";

    wtr_proc_alive_msg[31] = (getpid() + 48);
    write(CONSOLE, wtr_proc_alive_msg, sizeof(wtr_proc_alive_msg)-1);

    if (sem==-1){
        if((sem = screate(0)) == SYSERR){
            write(CONSOLE, "\nsem create failed\n", 19);
        }
    }

    if(wait(sem) == SYSERR){
        write(CONSOLE, "\nin wtr_func wait failed\n", 25);
    }

    write(CONSOLE, wtr_got_signal_msg, sizeof(wtr_got_signal_msg)-1);
}

void create_rcv(){
    char create_rcv_msg[]    = "\tIN CREATE WITH RCV\n";
    write(CONSOLE, create_rcv_msg, sizeof(create_rcv_msg)-1);

    if((rcv_func_pid = create(rcv_func, MINSTK, 20, "RCV", 1, 0)) == SYSERR){
        write(CONSOLE, "\ncreate rcv_func failed\n", 24);
    }
}

void rcv_func(){
    char rcv_proc_alive_msg[] = "\nRCV process is alive with pid N\n";
    char rcv_got_message_msg[] = "\nRCV received message\n";

    rcv_proc_alive_msg[31] = (getpid() + 48);
    write(CONSOLE, rcv_proc_alive_msg, sizeof(rcv_proc_alive_msg)-1);

    if(receive() == SYSERR){
        write(CONSOLE, "\nin rcv_func receive failed\n", 28);
    }

    write(CONSOLE, rcv_got_message_msg, sizeof(rcv_got_message_msg)-1);
}

void do_resume(int pid){
    char resume_msg[]        = "\tIN RESUME WITH pid X\n";
    resume_msg[20] = (char)(value + 48);
    write(CONSOLE, resume_msg, sizeof(resume_msg)-1);
    resume(pid);
}

void do_kill(int pid){
    char kill_msg[]          = "\tIN KILL WITH pid X\n";
    kill_msg[18] = (char)(pid + 48);
    write(CONSOLE, kill_msg, sizeof(kill_msg)-1);
    kill(pid);
}

void do_suspend(int pid){
    char suspend_msg[]          = "\tIN SUSP WITH pid X\n";
    suspend_msg[18] = (char)(pid + 48);
    write(CONSOLE, suspend_msg, sizeof(suspend_msg)-1);
    suspend(pid);
}

void create_slp(){
    char create_slp_msg[]    = "\tIN CREATE WITH SLP\n";
    write(CONSOLE, create_slp_msg, sizeof(create_slp_msg)-1);

    int slp_func_pid;
    if((slp_func_pid = create(slp_func, MINSTK, 20, "SLP", 0)) == SYSERR){
        write(CONSOLE, "\ncreate slp_func failed\n", 24);
    }
}

void slp_func(){
    char slp_proc_alive_msg[] = "\nSLP process is alive with pid N\n";
    char slp_will_sleep_msg[] = "\nSLP will now sleep for 120 seconds\n";

    slp_proc_alive_msg[31] = (getpid() + 48);
    write(CONSOLE, slp_proc_alive_msg, sizeof(slp_proc_alive_msg)-1);

    write(CONSOLE, slp_will_sleep_msg, sizeof(slp_will_sleep_msg)-1);

    sleep(120);

}

void show_proc(){
    sigset_t ps;

    char show_proc_msg[]        = "\tIN SHOW PROC\n";
    char proc_n_state_msg[]     = "\nPROC N STATE ";
    char ready_msg[]            = "READY\n";
    char current_msg[]          = "CURRENT\n";
    char free_msg[]             = "FREE\n";
    char recvwaiting_msg[]      = "RECVWAITING\n";
    char sleeping_msg[]         = "SLEEPING\n";
    char semwaiting_msg[]       = "SEMWAITING\n";
    char suspended_msg[]        = "SUSPENDED\n";

    write(CONSOLE, show_proc_msg, sizeof(show_proc_msg)-1);

    int i;
    /* Disable interrupts to show consistent view of processes states */
    disable(ps);

    for (i=0;i<NPROC;++i){
        proc_n_state_msg[6] = (char)(i+48); // insert the correct proc number into the message
        write(CONSOLE,proc_n_state_msg,sizeof(proc_n_state_msg)-1);
        switch(proctab[i].pstate){
        case PRCURR:
            write(CONSOLE,current_msg, sizeof(current_msg)-1);
            break;
        case PRFREE:
            write(CONSOLE,free_msg, sizeof(free_msg)-1);
            break;
        case PRREADY:
            write(CONSOLE,ready_msg, sizeof(ready_msg)-1);
            break;
        case PRRECV:
            write(CONSOLE,recvwaiting_msg, sizeof(recvwaiting_msg)-1);
            break;
        case PRSLEEP:
            write(CONSOLE,sleeping_msg, sizeof(sleeping_msg)-1);
            break;
        case PRSUSP:
            write(CONSOLE,suspended_msg, sizeof(suspended_msg)-1);
            break;
        case PRWAIT:
            write(CONSOLE,semwaiting_msg, sizeof(semwaiting_msg)-1);
            break;
        }
    }

    restore(ps);
}

void show_slp(){

    sigset_t ps;

    char show_slp_msg[]             = "\tIN SHOW SLP\n";
    char proc_n_wait_ticks_msg[]    = "\nPROC N WAIT TICKS           \n";

    write(CONSOLE, show_slp_msg, sizeof(show_slp_msg)-1);

    /* Disable interrupts to give a consistent view of the sleep queue */
    disable(ps);

    int next=clockq;
    while ((next=q[next].qnext) < NPROC){
        proc_n_wait_ticks_msg[6] = (char)(next+48); //convert the pid to ascii and insert into message
        itoa(q[next].qkey, &proc_n_wait_ticks_msg[19]); // convert the ticks to ascii and insert into message
        write(CONSOLE, proc_n_wait_ticks_msg, sizeof(proc_n_wait_ticks_msg)-1);
    }

    restore(ps);

}

void show_rdy(){

    sigset_t ps;

    char show_rdy_msg[]             = "\tIN SHOW RDY\n";
    char proc_n_priority_msg[]    = "\nPROC N PRIORITY   \n";

    write(CONSOLE, show_rdy_msg, sizeof(show_rdy_msg)-1);

    /* Disable interrupts to give a consistent view of the ready queue */
    disable(ps);

    int next=rdyhead;
    while ((next=q[next].qnext) < NPROC){
        proc_n_priority_msg[6] = (char)(next+48); //convert the pid to ascii and insert into message
        itoa(q[next].qkey, &proc_n_priority_msg[17]); // convert the ticks to ascii and insert into message
        write(CONSOLE, proc_n_priority_msg, sizeof(proc_n_priority_msg)-1);
    }

    restore(ps);

}

/* Adapted from: https://en.wikibooks.org/wiki/C_Programming/C_Reference/stdlib.h/itoa. Retrieved 2016-03-28. */
/* itoa:  convert n to characters in s */
 void itoa(int n, char *s)
 {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }
 /* Adapted from: https://en.wikibooks.org/wiki/C_Programming/C_Reference/stdlib.h/itoa. Retrieved 2016-03-28. */
 /* reverse:  reverse string s in place */
 void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
