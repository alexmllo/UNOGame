#ifndef JUGADORES_H
#define JUGADORES_H

#include "jugador.h"

#define MAX_CARTAS_UNO 76
#define MAX_NOM 20
#define MAX_JUGA 15


void mostrar_jugadores(tjugadores d,tpartida p);
void inicializar_jugadores(tjugadores *k,tbaraja *b);
void repartir_cartas_jugadores(tjugadores *jug, tbaraja *b);

#endif

