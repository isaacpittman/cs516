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
void prompt();
/* Force the lexer to use getchar() to get 1 character at a time */
#define YY_INPUT(buf,result,max_size) \
   { \
     fcntl (0, F_SETFL, O_NONBLOCK); \
     int c = getc(stdin); \
     while (c==-1 && errno==EAGAIN) c=getc(stdin); \
     buf[0]=c; \
     result=1; \
   }
%}

%{
/*Define a state that gets a procnum */
%}

%s getprocnum

digit [0-9]
procnum {digit}
%%

%{
/* * * * * * * * * 
 * * * RULES * * *
 * * * * * * * * */
%}
   /* possible XINU commands */
^resume[ ].+$ { 
     yyless(7); BEGIN(getprocnum);
}
<getprocnum>{procnum} { 
     write(1, "Resuming process:", 17); 
     write(1, yytext, 1); 
     write(1, "\n", 1); 
}
<getprocnum>.* { 
            write(1, yytext, yyleng);
            write(1, " is not valid procnum.\n",23);
            BEGIN(INITIAL);
          } 

^exit$ {
    return(0);
}

<<EOF>> ;

   /* The .* accumulates all the characters on any line that does not
      match a valid credit card number */
.* { printf("error: %s \n", yytext); }
\n { prompt(); }
%%

/* * * * * * * * * * * 
 * * * USER CODE * * *
 * * * * * * * * * * *
 */
void prompt() {
 write(1, "prompt>", 7);
}
void main() {
 yylex();
}
