#pragma once
#include "IO_funksjoner.h"
#include <stdio.h>

typedef enum {
    INITIALISER,
    STILLE,
    STOPP,
    VENT,
    OPP,
    NED
}tilstand;


typedef enum{
    FØRSTE,
    ANDRE,
    TREDJE,
    FJERDE,
    UDEFINERT = -1
}etasje;

extern tilstand *aktiv_tilstand;
void stopp_aktivert();
void sett_tilstand();
void stille();
void stopp();
void vent();
void opp();
void ned();



