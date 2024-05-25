#ifndef JUGADAS_H
#define JUGADAS_H

#include "jugada.h"

#define MAX_CARTAS_UNO 76
#define MAX_NOM 20
#define MAX_JUGADAS 15

typedef struct
{
    int num_jugadas;
    tjugada vjugadas[MAX_JUGADAS];
}tjugadas;

void mostrar_jugadas(tjugadas f,tpartida p);
void calcular_jugadas(tcarta descarte, tbaraja b, tjugadas *j);
void eliminar_jugadas(tjugadas *j, int pos);
int hay_jugada(tcarta mazodescartes, tbaraja mazojugador); //mazo descarte esta en tpartida//
int seleccionar_jugada(tjugadas numjugadas, tpartida p);
void anyadir_jugada(int pos, tcarta c, tjugadas *j);

#endif


