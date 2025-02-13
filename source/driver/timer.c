#include "timer.h"
#include "elevio.h"
#include <time.h>


static time_t starttid = -1;
static time_t aktiv_tid = -1;

void reset_timer(int restart){
    if (starttid == -1 || restart){
        starttid = time(NULL);
    }
};

int nedtelling(double sekunder){

    while (sekunder >= difftime(aktiv_tid,starttid)){
        aktiv_tid = time(NULL);
    }
    starttid = -1;
    return 1;
};

int nedtelling_dor(double sekunder){

    while (sekunder >= difftime(aktiv_tid,starttid)){
        aktiv_tid = time(NULL);
        if (elevio_obstruction()) {
            starttid = time(NULL);
        }
    }
    starttid = -1;
    return 1;
};
