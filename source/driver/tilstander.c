#include "tilstander.h"
#include "elevio.h" 
#include "timer.h"

//globale variabler 
tilstand *aktiv_tilstand = INITIALISER;
MotorDirection aktiv_retning;


void stopp_aktivert(tilstand *t){
    if (elevio_stopButton()){
        *t = STOPP; 
    }
};

void stille(tilstand *t){
    if (elevio_stopButton()){
        *t = STOPP;
    }

    elevio_doorOpenLamp(1);
    int *obstruksjon_indikator = 0;
    if (elevio_obstruction()) {
        //reset_timer(1); //rest timer
        *obstruksjon_indikator =  1;
        aktiv_retning = DIRN_STOP;   
    }
    //hvis obstruksjonsbryter er slått av og 
    if (!elevio_obstruction() && *obstruksjon_indikator == 1) {
        reset_timer(1);
        if (nedtelling(3)){
            elevio_doorOpenLamp(0);
            *aktiv_tilstand = VENT;
        }
        *obstruksjon_indikator = 0;


    }

};

void stopp(tilstand *t) {

};

void vent(tilstand *t) {
    
};
void opp(tilstand *t) {
    
};
void ned(tilstand *t) {
    
};


//definer tilstand
void sett_tilstand(){
    switch(*aktiv_tilstand){
        case (INITIALISER):

        
        break;

        case (STILLE):
        stopp_aktivert(aktiv_tilstand);
        stille(aktiv_tilstand);

        break;

        case (STOPP):
        stopp_aktivert(aktiv_tilstand);
        
        break;

        case (VENT):
        stopp_aktivert(aktiv_tilstand);
        
        break;

        case (OPP):
        stopp_aktivert(aktiv_tilstand);
        
        break;

        case (NED):
        stopp_aktivert(aktiv_tilstand);
        
        break;


        
    }
}


