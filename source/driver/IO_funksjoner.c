#include "IO_funksjoner.h"
#include "elevio.h"


void all_lys_av(){
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
            int btnPressed = elevio_callButton(f, b);
            elevio_buttonLamp(f, b, btnPressed);
        }
    }
};


void etasjelys(){
    int etasje = elevio_floorSensor();
    if (etasje != -1){
        elevio_floorIndicator(etasje);
        printf("hei\n");
    }
}

int bestilling_heis(){
    for(int f = 0; f < N_FLOORS; f++){
        int btnPressed = elevio_callButton(f, 2);
        elevio_buttonLamp(f, 2, btnPressed);
        return f;
        }
        return -2; //returner -2 dersom det ikke er noen bestillinger inne i heisen
    };

int bestilling_etasje_ned(){
    for(int f = 0; f < N_FLOORS; f++){
        int btnPressed = elevio_callButton(f, 1);
        elevio_buttonLamp(f, 1, btnPressed);
        return f;
    }
        return -2;
};

int bestilling_etasje_opp(){
    for(int f = 0; f < N_FLOORS; f++){
        int btnPressed = elevio_callButton(f, 0);
        elevio_buttonLamp(f, 0, btnPressed);
        return f;
    }
        return -2;
};



