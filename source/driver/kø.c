#include "kø.h"
#include <stdlib.h>
#include <stdio.h>


ordrekø *opp_liste;
ordrekø *ned_liste;



void lag_liste_ned(){
    if (ned_liste == NULL) {
        ned_liste = malloc(sizeof(ordrekø));
    }
    int bestilling_innside_heis = bestilling_heis();
    if (bestilling_innside_heis < aktiv_etasje()){
        ned_liste -> ordre[bestilling_innside_heis] = 1;
    }
    for (int f = aktiv_etasje(); f >= 0; f--){
        int btnPressed = elevio_callButton(f, 1);
        if (btnPressed == 1){
            ned_liste -> ordre[f] = 1;
        }
    }
};
int hent_neste_opp() {
    for (int f = aktiv_etasje(); f < N_FLOORS; f++){
        if (opp_liste -> ordre[f] == 1){
            return f;
        }
    }
    return -1;
};

void lag_liste_opp(){
    if (opp_liste == NULL) {
        opp_liste = malloc(sizeof(ordrekø));
    }
    int bestilling_innside_heis = bestilling_heis();
    if (bestilling_innside_heis > aktiv_etasje()){
        opp_liste -> ordre[bestilling_innside_heis] = 1;
    }
    for (int f = aktiv_etasje(); f < N_FLOORS; f++){
        int btnPressed = elevio_callButton(f, 0);
        if (btnPressed == 1){
            opp_liste -> ordre[f] = 1;
        }
    }
};

int hent_neste_ned() {
    for (int f =aktiv_etasje(); f >= 0; f--){
        if (ned_liste -> ordre[f] == 1){
            return f;
        }
    }
    return -1;
};





