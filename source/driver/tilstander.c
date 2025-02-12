#include "tilstander.h"
#include "elevio.h"
#include "timer.h"
#include "IO_funksjoner.h"


//globale variabler 
tilstand start_tilstand = STILLE;
tilstand *aktiv_tilstand = &start_tilstand;




void stille(){
    
    elevio_doorOpenLamp(1);
    reset_timer(1);
    while(!nedtelling(3)){
        elevio_motorDirection(DIRN_STOP);
        int obstruksjon_indikator = 0;

        if (elevio_obstruction()) {
            //reset_timer(1); //rest timer
            obstruksjon_indikator =  1;  
        }
    
        //hvis obstruksjonsbryter er slått av og 
        if (!elevio_obstruction() && obstruksjon_indikator == 1){
            reset_timer(1);
            if (nedtelling(3)){
                elevio_doorOpenLamp(0);
                *aktiv_tilstand = VENT;
            }
            obstruksjon_indikator = 0;
        }
        

    }

    elevio_doorOpenLamp(0);
    *aktiv_tilstand = VENT;



};

void stopp() {
    elevio_motorDirection(DIRN_STOP); //stopper heisen
    int stopp_indikator = 0;
    all_lys_av();
    //tøm bestillingskøen
 
    while (elevio_stopButton()) {
         //Ignorer alle forsøk på bestillinger

        elevio_stopLamp(1);
        if(elevio_floorSensor() != -1) {
            elevio_doorOpenLamp(1); //åpne døren
            stopp_indikator =  1;
        }     
}
    elevio_stopLamp(0);
    if (!elevio_stopButton() && stopp_indikator == 0){
        reset_timer(1);
        if (nedtelling(3)){
            elevio_doorOpenLamp(0);
            *aktiv_tilstand = VENT; //står i ro og venter nye bestillinger
        }
    }
        

    };


void vent() {

    
    int aktiv_etasje = elevio_floorSensor();

    

};
void opp() {
    
};
void ned() {
    
};


//definer tilstand
void sett_tilstand(){
    switch(*aktiv_tilstand){
        case (INITIALISER):
        


        
        break;

        case (STILLE):
        stopp_aktivert();
        stille();

        break;

        case (STOPP):
        stopp_aktivert();
        stopp();
        
        break;

        case (VENT):
        printf("Hei\n");
        stopp_aktivert();
        printf("Hei2\n");

        
        break;

        case (OPP):
        stopp_aktivert();
        
        break;

        case (NED):
        stopp_aktivert();
        
        break;


        
    }
}


