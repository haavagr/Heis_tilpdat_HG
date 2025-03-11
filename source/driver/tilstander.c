#include "tilstander.h"




//globale variabler 
tilstand start_tilstand = INITIALISER;
tilstand *aktiv_tilstand = &start_tilstand;







void stille(){
    lag_liste_opp();
    lag_liste_ned();
    etasjelys();
    bestillingslys();
    elevio_doorOpenLamp(1);
    reset_timer(1);
    elevio_motorDirection(DIRN_STOP); 
    if (nedtelling_dor(3)){
            elevio_doorOpenLamp(0);
            *aktiv_tilstand = VENT;
    } 
};

void stopp() {
    elevio_motorDirection(DIRN_STOP); //stopper heisen
    bestillingslys_av();
    tom_lister (); //tømmer bestillingskøen

 
    while (elevio_stopButton()){
        for (int f = 0; f < N_FLOORS; f++){ //ignorerer alle forsøk på bestillinger mens stoppknappen er trykket ned
            ned_liste -> ordre[f] = 0;
            opp_liste -> ordre[f] = 0;
            }

        elevio_stopLamp(1);
        if (elevio_floorSensor() != -1) {
            elevio_doorOpenLamp(1);
            *aktiv_tilstand = STILLE;
    
        } else {
            *aktiv_tilstand = VENT;
        }    
    }
    elevio_stopLamp(0);
        

    };


void vent() {
    stopp_aktivert();
    if (*aktiv_tilstand == STOPP){
        return;
    }
    lag_liste_opp();
    lag_liste_ned();
    etasjelys();
    bestillingslys();
    int neste_opp = hent_neste_opp();
    int neste_ned = hent_neste_ned();
    if (neste_opp != -1) {
        *aktiv_tilstand = OPP;
    } else if (neste_ned != -1) {
        *aktiv_tilstand = NED;
    } else {
        *aktiv_tilstand = VENT;
    }
};

void opp() {
        lag_liste_opp();
        lag_liste_ned();
        stopp_aktivert();
        etasjelys();
        bestillingslys();
        int etasje = elevio_floorSensor();
        elevio_motorDirection(DIRN_UP);
        if (etasje != -1){
            
            if (opp_liste->ordre[etasje] == 1) {
                opp_liste -> ordre[etasje] = 0;
                ned_liste -> ordre[etasje] = 0;
                
                *aktiv_tilstand = STILLE;
            } else {
                *aktiv_tilstand = OPP;
            }
        } 
        if (etasje == 3){
            *aktiv_tilstand = STILLE;
        }
    
};


void ned() {
    lag_liste_opp();
    lag_liste_ned();
    stopp_aktivert();
    etasjelys();
    bestillingslys();
    int etasje = elevio_floorSensor();
    elevio_motorDirection(DIRN_DOWN); 
    if (etasje != -1){
        if (ned_liste -> ordre[etasje] == 1) {
            ned_liste -> ordre[etasje] = 0;
            opp_liste -> ordre[etasje] = 0;
            *aktiv_tilstand = STILLE;
        } else {
        *aktiv_tilstand = NED;
        }
    }
    if (etasje == 0){
        *aktiv_tilstand = STILLE;
}
};

void initialiser(){
    etasjelys();
    while (aktiv_etasje() != 1) {
        if (aktiv_etasje() < 1) {
            elevio_motorDirection(DIRN_UP);
        } else {
            elevio_motorDirection(DIRN_DOWN);
        }
        }
    *aktiv_tilstand = STILLE;

};


//definer tilstand
void sett_tilstand(){
    switch(*aktiv_tilstand){
        case (INITIALISER):
        initialiser();

        
        break;

        case (STILLE):
        stille();

        break;

        case (STOPP):
        stopp();

        break;

        case (VENT):
        vent();
        

        
        break;

        case (OPP):
        opp();
        
        break;

        case (NED):
        ned();
        

        
        break;


        
    }
}


