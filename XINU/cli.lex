%option noyywrap
%option noyyalloc
%option noyyrealloc
%option noyyfree
%{
/* * * * * * * * * * * *
 * * * DEFINITIONS * * *
 * * * * * * * * * * * */
%}

%{
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "kernel.h"
#include "stdio.h"
#include "cli.h" /* Contains the TKN_ token definitions */
#include "conf.h"

/* The value of a returned token. For example, the procnum when resuming */
extern int yylval;

/* The function that displays the prompt */
void prompt();

/* Functions to get and release memory using XINU functions */
void * yyalloc (size_t size);
void   yyfree (void * ptr);
void * yyrealloc (void * ptr, size_t size);
typedef struct{
        int  state;
        void *getmem_adr;
        int  size;
}MEMALLOC;
MEMALLOC     memarray[500];
int memarray_max = 0;


#define YY_INPUT(buf,result,max_size) \
   { \
     int n,x; \
     while ((n=read(CONSOLE, buf, 0))==0){ \
        for(x=0; x<100000000; ++x); \
     } \
     result=n; \
   }
/* The token that will be returned by the lexer */
int currentToken;
%}

%{
/*Define a state that gets a procnum */
%}
%s getprocnum

%{
/* A process number is a single numeric digit */
%}
procnum [0-9]
%%

%{
/* * * * * * * * * 
 * * * RULES * * *
 * * * * * * * * */
%}
   /* Whenever yylex is called, we will start in the INITIAL state rather than the most recent state */
   BEGIN(INITIAL);

   /* possible XINU commands */
^resume[ ].+$ { 
     yyless(7); currentToken=TKN_RESUME; BEGIN(getprocnum);
}
^kill[ ].+$ { 
     yyless(5); currentToken=TKN_KILL; BEGIN(getprocnum);
}
^suspend[ ].+$ { 
     yyless(8); currentToken=TKN_SUSPEND; BEGIN(getprocnum);
}
<getprocnum>{procnum} { 
     yylval=atoi(yytext);
     return currentToken;
}
<getprocnum>.* { 
            write(0, yytext, yyleng);
            write(0, " is not valid procnum.\n",23);
            BEGIN(INITIAL);
          } 

^show\ proc$ {
     return TKN_SHOW_PROC;
}

^show\ slp$ {
     return TKN_SHOW_SLP;
}

^show\ rdy$ {
     return TKN_SHOW_RDY;
}

^create\ slp$ {
     return TKN_CREATE_SLP;
}

^create\ rcv$ {
     return TKN_CREATE_RCV;
}

^create\ rdy$ {
     return TKN_CREATE_RDY;
}

^create\ wtr$ {
     return TKN_CREATE_WTR;
}

^create\ snd {
     return TKN_CREATE_SND;
}

^create\ sig {
     return TKN_CREATE_SIG;
}

^exit$ {
    return TKN_EXIT;
}

   /* The .* accumulates all the characters on any line that does not
      match a valid XINU command */
.* { write(0,"error: ",7); write(0,yytext,strlen(yytext)); write(0,"\n",1); }

   /* Print a prompt after every newline */
\n { prompt(); }

%%

/* * * * * * * * * * * 
 * * * USER CODE * * *
 * * * * * * * * * * *
 */
void prompt() {
    write(0, "prompt>", 7);
}

/* Provide our own implementations. */
void * yyalloc (size_t size){
    int z;
    for(z=0; z<500; ++z){
        if(memarray[z].state)
        {
            continue;
        }
        else {
               memarray[z].state = 1;
               memarray[z].getmem_adr = getmem((int)size);
               if((int)memarray[z].getmem_adr == SYSERR)return(NULL);
               memarray[z].size = size;
               if(memarray_max < (z + 1))memarray_max = z + 1;
               return(memarray[z].getmem_adr);
        }
     }
}

void * yyrealloc (void * ptr, size_t size) {
    int z;
    for(z=0; z<memarray_max; ++z){
        if(memarray[z].getmem_adr == ptr){
          if(memarray[z].state)memarray[z].state = 0;
          else continue;
          if(freemem((struct mblock *)ptr, memarray[z].size) == SYSERR)return(NULL);
          if(memarray_max == (z + 1))--z;
          break;
        }
    }
    for(z=0; z<500; ++z){
     if(memarray[z].state)continue;
     else { memarray[z].state = 1;
            memarray[z].getmem_adr = getmem((int)size);
            if((int)memarray[z].getmem_adr == SYSERR)return(NULL);
            memarray[z].size = size;
            if(memarray_max < (z + 1))memarray_max = z + 1;
            return(memarray[z].getmem_adr);
     }
    }
}

void   yyfree (void * ptr){
    int z;
      for(z=0; z<500; ++z){
            if(memarray[z].getmem_adr == ptr){
                    if(memarray[z].state)memarray[z].state = 0;
                    else continue;
                    if(freemem((struct mblock *)ptr, memarray[z].size) == SYSERR)return;
                    if(memarray_max == (z + 1))--z;
                    return;
            }
      }
    return;
}
