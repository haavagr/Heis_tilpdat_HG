#include "IO_funksjoner.h"


etasje forrige;
etasje bestilling;


void bestillingslys_av(){
    for(int f = 0; f < N_FLOORS; f++){
        for(int b = 0; b < N_BUTTONS; b++){
            elevio_buttonLamp(f, b, 0);
        }
    }
}

void stopp_aktivert(){
    if (elevio_stopButton()){
        *aktiv_tilstand = STOPP; 
    }
};

void bestillingslys(){
    for(int f = 0; f < N_FLOORS; f++){
        for(int b = 0; b < N_BUTTONS; b++){
            if (elevio_callButton(f, b)) {
                elevio_buttonLamp(f, b, 1);
            } //trenger kode for å skru av lys utenfor kabinen
        }
    }
    if (aktiv_etasje() == bestilling_heis()) {
        elevio_buttonLamp(aktiv_etasje(), 2, 0);
    }

};


void etasjelys(){
    int etasje = elevio_floorSensor();
    if (etasje != -1){
        elevio_floorIndicator(etasje);
    }
}
int aktiv_etasje(){
    int etasje = elevio_floorSensor();
    if (etasje != -1){
        forrige = etasje;
    }
    return forrige;

   
       
};

int bestilling_heis(){
    for(int f = 0; f < N_FLOORS; f++){
        int btnPressed = elevio_callButton(f, 2);
        if (btnPressed) {
        bestilling = f;
        }
        }
        return bestilling;
         //returner -2 dersom det ikke er noen bestillinger inne i heisen
    };







