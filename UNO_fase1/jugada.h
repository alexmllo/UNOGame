#ifndef JUGADA_H
#define JUGADA_H

#include "baraja.h"

typedef struct
{
    int nc;      //*horario = 1,   antihorario = -1*//
    tcarta carta;         //color i numero sirve para saber que carta está en la mesa//
}tjugada;

void mostrar_jugada(tjugada d,tpartida p);

#endif


