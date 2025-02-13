#pragma once
#include "tilstander.h"

typedef struct {
    int ordre[N_FLOORS];
}ordrekø;

extern ordrekø *opp_liste;
extern ordrekø *ned_liste;


void lag_liste_ned();
void lag_liste_opp();