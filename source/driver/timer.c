#include "timer.h"
#include <time.h>

static time_t starttid = -1;
static time_t aktiv_tid = -1;

void reset_timer(int restart){
    if (starttid == -1 || restart){
        starttid = time(NULL);
    }
};

int nedtelling(double sekunder){
    aktiv_tid = time(NULL);
    if (sekunder < difftime(aktiv_tid,starttid)){
        starttid = -1; 
        return 1;

    }
    return 0;
};

