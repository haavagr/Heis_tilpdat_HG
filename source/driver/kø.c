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
    if ((-1 < bestilling_innside_heis) && (bestilling_innside_heis < aktiv_etasje())){
        ned_liste -> ordre[bestilling_innside_heis] = 1;
        printf("Plassering: %d\n", bestilling_innside_heis);
    }
    for (int f = aktiv_etasje(); f >= 0; f--){

        int btnPressed_opp = (elevio_callButton(f,0) == 1 && hent_neste_ned() == -1);
        int btnPressed_ned = elevio_callButton(f,1);
        if (( btnPressed_opp || btnPressed_ned) && (f <= aktiv_etasje())){
            ned_liste -> ordre[f] = 1;
            printf("Plassering utside: %d\n", f);

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
        printf("Plassering: %d\n", bestilling_innside_heis);
    }
    for (int f = aktiv_etasje(); f < N_FLOORS; f++){
        
        int btnPressed_ned = (elevio_callButton(f,1) && hent_neste_opp() == -1);
        int btnPressed_opp = elevio_callButton(f,0);
        if (((btnPressed_opp == 1) || btnPressed_ned) && (f > aktiv_etasje())){
            opp_liste -> ordre[f] = 1;
            printf("Plassering utside: %d\n", f);


        }
    }
};

int hent_neste_ned() {
    for (int f = aktiv_etasje(); f >= 0; f--){
        if (ned_liste -> ordre[f] == 1){
            return f;
        }
    }
    return -1;
};
void tom_lister () {
    //endre lengden på løkken
    for (int f = 0; f < N_FLOORS; f++){
        ned_liste-> ordre[f] = 0;
        opp_liste-> ordre[f] = 0;
    }
};




