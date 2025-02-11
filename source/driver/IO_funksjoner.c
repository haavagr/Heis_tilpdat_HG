#include "IO_funksjoner.h"
#include "elevio.h"

void all_lys_av(){
    for(int f = 0; f < N_FLOORS; f++){
        for(int b = 0; b < N_BUTTONS; b++){
            elevio_buttonLamp(f, b, 0);
        }
    }
}

