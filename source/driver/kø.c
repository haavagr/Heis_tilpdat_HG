#include "kø.h"
#include "tilstander.h"
#include <stdio.h>

etasje bestilling;



int opp_liste[N_FLOORS];
int ned_liste[N_FLOORS];

void lag_liste_ned(){
    int bestilling_innside_heis = bestilling_heis();
    if (bestilling_innside_heis < aktiv_etasje()){
        ned_liste[bestilling_innside_heis] = 1;
    }
    for(int f = N_FLOORS; f >= 0; f--){
        int btnPressed = elevio_callButton(f, 1);
        ned_liste[f] = btnPressed;
    }
};

void lag_liste_opp(){
    int bestilling_innside_heis = bestilling_heis();
    if (bestilling_innside_heis > aktiv_etasje()){
        opp_liste[bestilling_innside_heis] = 1;
    }
    for(int f = 0; f < N_FLOORS; f++){
        int btnPressed = elevio_callButton(f, 0);
        opp_liste[f] = btnPressed;
    }
};



void lag_kø(ordrekø *opp, ordrekø *ned, int aktiv_etasje){
    for (int f = 0; f < N_FLOORS; f++) {
        
    }
}





