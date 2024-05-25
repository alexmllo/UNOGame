#ifndef JUGADOR_H
#define JUGADOR_H

#include "jugadas.h"

#define MAX_CARTAS_UNO 108
#define MAX_NOM 20

int jugador_tiene_carta(tjugador mazojugador, tcarta b);
void mostrar_jugador(tjugador j,tpartida p, int pos);

#endif
