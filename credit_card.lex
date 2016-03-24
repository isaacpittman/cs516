%option noyywrap
%{
/* * * * * * * * * * * *
 * * * DEFINITIONS * * *
 * * * * * * * * * * * */
%}

%{
#define YY_INPUT(buf,result,max_size) \
    { \
    int c = getchar(); \
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
    }
// recognize whether or not a credit card number is valid
int line_num = 1;
extern void prompt();
%}

%s resume

digit [0-9]
group {digit}{4}
procnum {digit}
%%

%{
/* * * * * * * * * 
 * * * RULES * * *
 * * * * * * * * */
%}
   /* The carat (^) says that a credit card number must start at the
      beginning of a line and the $ says that the credit card number
      must end the line. */
^{group}([ -]?{group}){3}$  { printf(" credit card number: %s\n", yytext); }

   /* possible XINU commands */
^resume[ ].+$ { 
     yyless(7); BEGIN(resume);
}
<resume>{procnum} { 
     write(1, "Resuming process:", 17); 
     write(1, yytext, 1); 
     write(1, "\n", 1); 
}
<resume>.* { 
            write(1, yytext, yyleng);
            write(1, " is not valid procnum.\n",23);
            BEGIN(INITIAL);
          } 

   /* The .* accumulates all the characters on any line that does not
      match a valid credit card number */
.* { printf("%d: error: %s \n", line_num, yytext); }
\n { line_num++; prompt(); }
%%

/* * * * * * * * * * * 
 * * * USER CODE * * *
 * * * * * * * * * * *
 */
int main(int argc, char *argv[]) {
  yylex();
}
