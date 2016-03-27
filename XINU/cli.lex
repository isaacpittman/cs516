%option noyywrap
%{
/* * * * * * * * * * * *
 * * * DEFINITIONS * * *
 * * * * * * * * * * * */
%}

%{
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "cli.h" /* Contains the TKN_ token definitions */

/* The value of a returned token. For example, the procnum when resuming */
extern int yylval;

/* The function that displays the prompt */
void prompt();

/* Force the lexer to use getc() to get 1 character at a time */
/* Set stdin to non-blocking mode, and keep trying to get characters until EOF */
#define YY_INPUT(buf,result,max_size) \
   { \
     fcntl (0, F_SETFL, O_NONBLOCK); \
     int c = getc(stdin); \
     while (c==-1 && errno==EAGAIN) c=getc(stdin); \
     result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
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
   /* possible XINU commands */
^resume[ ].+$ { 
     yyless(7); currentToken=TKN_RESUME; BEGIN(getprocnum);
}
^kill[ ].+$ { 
     yyless(5); currentToken=TKN_KILL; BEGIN(getprocnum);
}
<getprocnum>{procnum} { 
     yylval=atoi(yytext);
     return currentToken;
}
<getprocnum>.* { 
            write(1, yytext, yyleng);
            write(1, " is not valid procnum.\n",23);
            BEGIN(INITIAL);
          } 

^show\ proc$ {
     return TKN_SHOW_PROC;
}

^show\ slp$ {
     return TKN_SHOW_SLP;
}

^create\ slp$ {
     return TKN_CREATE_SLP;
}

^create\ rcv$ {
     return TKN_CREATE_RCV;
}

^create\ wtr$ {
     return TKN_CREATE_WTR;
}

^exit$ {
    return TKN_EXIT;
}

   /* The .* accumulates all the characters on any line that does not
      match a valid XINU command */
.* { printf("error: %s \n", yytext); }

   /* Print a prompt after every newline */
\n { prompt(); }
%%

/* * * * * * * * * * * 
 * * * USER CODE * * *
 * * * * * * * * * * *
 */
void prompt() {
 write(1, "prompt>", 7);
}
