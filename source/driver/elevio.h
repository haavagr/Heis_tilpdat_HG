#pragma once


#define N_FLOORS 4

typedef enum { 
    DIRN_DOWN   = -1,
    DIRN_STOP   = 0,
    DIRN_UP     = 1
} MotorDirection;


#define N_BUTTONS 3

typedef enum { 
    BUTTON_HALL_UP      = 0,
    BUTTON_HALL_DOWN    = 1,
    BUTTON_CAB          = 2
} ButtonType;


void elevio_init(void);

//Setter retning
void elevio_motorDirection(MotorDirection dirn);
//Setter lys til alle bestillingsknapper
void elevio_buttonLamp(int floor, ButtonType button, int value);
//Setter etasjelys på panel
void elevio_floorIndicator(int floor);
//Lys til dør åpen
void elevio_doorOpenLamp(int value);
//Lys stoppknapp
void elevio_stopLamp(int value);

//Henter hvilken etasje en bestillingsknapp er trykket, med 
int elevio_callButton(int floor, ButtonType button);
//Gir ut hvilken etasje man er i, -1 dersom heisen er i bevegelse
int elevio_floorSensor(void);
//Gir ut 1 dersom stoppknapp er trykket inn
int elevio_stopButton(void);
//Gir ut 1 når obstruksjonsbryteren er på
int elevio_obstruction(void);

