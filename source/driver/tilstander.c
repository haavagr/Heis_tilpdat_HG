#include "tilstander.h"




//globale variabler 
tilstand start_tilstand = INITIALISER;
tilstand *aktiv_tilstand = &start_tilstand;
tilstand *forrige_tilstand = &start_tilstand;

int aktiv_retning = 1;




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
    //tømmer bestillingskøen
    for (int f = 0; f < N_FLOORS; f++){
        ned_liste -> ordre[f] = 0;
        opp_liste -> ordre[f] = 0;
        }

 
    while (elevio_stopButton()){
        for (int f = 0; f < N_FLOORS; f++){ //ignorerer alle forsøk på bestillinger mens stoppknappen er trykket ned
            ned_liste -> ordre[f] = 0;
            opp_liste -> ordre[f] = 0;
            }

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
    int etasje = aktiv_etasje();
    if (hent_neste_opp()!= -1) {
        *aktiv_tilstand = OPP;
    } else if (hent_neste_ned()!= -1) {
        *aktiv_tilstand = NED;
    } else {
        *aktiv_tilstand = VENT;
    }
};

void opp() {
        lag_liste_opp();
        lag_liste_ned();
        aktiv_retning = 1;
        int etasje = elevio_floorSensor();
        elevio_motorDirection(DIRN_UP); //byttes ut
        if (etasje != -1){
            
            if (opp_liste->ordre[etasje] == 1) {
                opp_liste -> ordre[etasje] = 0;
                ned_liste -> ordre[etasje] = 0;
                *aktiv_tilstand = STILLE;
                    printf("=== ===\n");
            } else {
                *aktiv_tilstand = OPP;
            }
        } 
        if (etasje == 3){
            *aktiv_tilstand = STILLE;
        }
    
};


void ned() {
    aktiv_retning = 0;
    int etasje = elevio_floorSensor();
    elevio_motorDirection(DIRN_DOWN); //byttes ut
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
        etasjelys();
        bestillingslys();
        initialiser();

        
        break;

        case (STILLE):
        lag_liste_opp();
        lag_liste_ned();
        stopp_aktivert();
        etasjelys();
        bestillingslys();
        stille();

        break;

        case (STOPP):
        //tømme lister
        //ignorere bestillinger
        stopp_aktivert();
        etasjelys();
        bestillingslys();
        stopp();

        break;

        case (VENT):
        lag_liste_opp();
        lag_liste_ned();
        stopp_aktivert();
        etasjelys();
        bestillingslys();
        vent();
        

        
        break;

        case (OPP):
        
        stopp_aktivert();
        etasjelys();
        bestillingslys();
        opp();
        
        break;

        case (NED):
        lag_liste_opp();
        lag_liste_ned();
        stopp_aktivert();
        etasjelys();
        bestillingslys();
        ned();
        

        
        break;


        
    }
}


