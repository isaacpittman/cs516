#ifndef CLI_H
#define CLI_H

/* Define the tokens used by the the Command Line Interpreter's lexical analyzer. */
#define TKN_SHOW_PROC   0
#define TKN_SHOW_SLP    1
#define TKN_RESUME      2
#define TKN_KILL        3
#define TKN_EXIT        4
#define TKN_CREATE_SLP  5
#define TKN_CREATE_RCV  6
#define TKN_CREATE_WTR  7
#define TKN_CREATE_SIG  8
#define TKN_CREATE_SND  9
#define TKN_SHOW_RDY    10
#define TKN_SUSPEND     11
#define TKN_CREATE_RDY  12

void start_cli();

#endif
