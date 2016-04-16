#include "conf.h"
#include "kernel.h"
#include "io.h"

/*Instead of using assembly code to find correct imap entry, we just hardcode console
 * and find the correct imap entry based on the signal */
void ioint(int sig_num){
    int descrp  = CONSOLE;
    struct  intmap  *map;

    map = &intmap[descrp];

    switch(sig_num){
    case SIGUSR1:
        map->iin(map->icode);
        break;
    case SIGUSR2:
        map->iout(map->ocode);
        break;
    }
}
