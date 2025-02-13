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
    elevio_motorDirection(DIRN_STOP); //skal ikke trenges
    if (nedtelling_dor(3)){
            elevio_doorOpenLamp(0);
            *aktiv_tilstand = VENT;
    } 
};

void stopp() {
    elevio_motorDirection(DIRN_STOP); //stopper heisen
    bestillingslys_av();
    //tøm bestillingskøen
 
    while (elevio_stopButton()){
         //Ignorer alle forsøk på bestillinger

        elevio_stopLamp(1);
        if (elevio_floorSensor() != -1) {
            *aktiv_tilstand = STILLE;
    
        } else {
            *aktiv_tilstand = VENT;
        }    
    }
    elevio_stopLamp(0);
        

    };


void vent() {
    bestillingslys();
    int etasje = aktiv_etasje();
    int bestillingsplassering = bestilling_heis();
    if (bestillingsplassering < etasje) {
        *aktiv_tilstand = NED;
    } else if (bestillingsplassering > etasje){
        *aktiv_tilstand = OPP;
    } else {
        *aktiv_tilstand = STILLE;
    }

};
void opp() {
    while (1) {
        int etasje = aktiv_etasje();
        lag_liste_opp();
        elevio_motorDirection(DIRN_UP); //bytter ut
        for (int i = etasje; i < N_FLOORS; i++){
            if (lag_liste_opp[etasje] )
        }
        if (lag_liste_opp[0] == etasje) {
            *aktiv_tilstand=STILLE;
        }
       


    }
};
void ned() {
    elevio_motorDirection(DIRN_DOWN);

     *aktiv_tilstand=STILLE;
};


//definer tilstand
void sett_tilstand(){
    switch(*aktiv_tilstand){
        case (INITIALISER):
        etasjelys();


        
        break;

        case (STILLE):
        stopp_aktivert();
        etasjelys();
        stille();

        break;

        case (STOPP):
        stopp_aktivert();
        etasjelys();
        stopp();

        break;

        case (VENT):
        etasjelys();
        stopp_aktivert();
        vent();
        

        
        break;

        case (OPP):
        stopp_aktivert();
        etasjelys();
        opp();
        
        break;

        case (NED):
        stopp_aktivert();
        etasjelys();
        ned();
        

        
        break;


        
    }
}


