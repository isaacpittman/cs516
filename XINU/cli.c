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
void    create_slp();

/* Dummy processes */
void    slp_func();

int token;
int value;
char resume_msg[]        = "\tIN RESUME WITH pid X\n";
char kill_msg[]          = "\tIN KILL WITH pid X\n";
char create_rcv_msg[]    = "\tIN CREATE WITH RCV\n";
char create_wtr_msg[]    = "\tIN CREATE WITH WTR\n";
char exit_msg[]          = "\tCOMMAND LINE INTERPRETER IS DONE, GOODBYE\n";

void start_cli() {
    prompt();

    while((token = yylex()) != TKN_EXIT) {

        switch (token) {
        case TKN_RESUME:
            value = yylval;
            resume_msg[20] = (char)(value + 48);
            write(1, resume_msg, sizeof(resume_msg)-1);
            break;
        case TKN_KILL:
            value = yylval;
            kill_msg[18] = (char)(value + 48);
            write(1, kill_msg, sizeof(kill_msg)-1);
            break;
        case TKN_SHOW_PROC:
            show_proc();
            break;
        case TKN_SHOW_SLP:
            show_slp();
            break;
        case TKN_CREATE_SLP:
            create_slp();
            break;
        case TKN_CREATE_RCV:
            write(1, create_rcv_msg, sizeof(create_rcv_msg)-1);
            break;
        case TKN_CREATE_WTR:
            write(1, create_wtr_msg, sizeof(create_wtr_msg)-1);
            break;
        }
    }

    write(1, exit_msg, sizeof(exit_msg)-1);
}

void create_slp(){
    char create_slp_msg[]    = "\tIN CREATE WITH SLP\n";
    write(1, create_slp_msg, sizeof(create_slp_msg)-1);

    int slp_func_pid;
    if((slp_func_pid = create(slp_func, MINSTK, 20, "SLP", 1, 0)) == SYSERR){
        write(1, "\ncreate slp_func failed\n", 24);
    }
    resume(slp_func_pid);
}

void slp_func(int unused){
    char slp_proc_alive_msg[] = "\nSLP process is alive with pid N\n";
    char slp_will_sleep_msg[] = "\nSLP will now sleep for 120 seconds\n";

    slp_proc_alive_msg[31] = (getpid() + 48);
    write(1, slp_proc_alive_msg, sizeof(slp_proc_alive_msg)-1);

    write(1, slp_will_sleep_msg, sizeof(slp_will_sleep_msg)-1);

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

    write(1, show_proc_msg, sizeof(show_proc_msg)-1);

    int i;
    /* Disable interrupts to show consistent view of processes states */
    disable(ps);

    for (i=0;i<NPROC;++i){
        proc_n_state_msg[6] = (char)(i+48); // insert the correct proc number into the message
        write(1,proc_n_state_msg,sizeof(proc_n_state_msg)-1);
        switch(proctab[i].pstate){
        case PRCURR:
            write(1,current_msg, sizeof(current_msg)-1);
            break;
        case PRFREE:
            write(1,free_msg, sizeof(free_msg)-1);
            break;
        case PRREADY:
            write(1,ready_msg, sizeof(ready_msg)-1);
            break;
        case PRRECV:
            write(1,recvwaiting_msg, sizeof(recvwaiting_msg)-1);
            break;
        case PRSLEEP:
            write(1,sleeping_msg, sizeof(sleeping_msg)-1);
            break;
        case PRSUSP:
            write(1,suspended_msg, sizeof(suspended_msg)-1);
            break;
        case PRWAIT:
            write(1,semwaiting_msg, sizeof(semwaiting_msg)-1);
            break;
        }
    }

    restore(ps);
}

void show_slp(){

    sigset_t ps;

    char show_slp_msg[]             = "\tIN SHOW SLP\n";
    char proc_n_wait_ticks_msg[]    = "\nPROC N WAIT TICKS           \n";

    write(1, show_slp_msg, sizeof(show_slp_msg)-1);

    /* Disable interrupts to give a consistent view of the sleep queue */
    disable(ps);

    int next=clockq;
    while ((next=q[next].qnext) < NPROC){
        proc_n_wait_ticks_msg[6] = (char)(next+48); //convert the pid to ascii and insert into message
        itoa(q[next].qkey, &proc_n_wait_ticks_msg[19]); // convert the ticks to ascii and insert into message
        write(1, proc_n_wait_ticks_msg, sizeof(proc_n_wait_ticks_msg)-1);
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
