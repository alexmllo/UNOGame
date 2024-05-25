#ifndef PARTIDA_H
#define PARTIDA_H

#include "jugadores.h"
#include "preguntas.h"

#define MAX_CARTAS_UNO 108
#define MAX_NOM 20
#define MAX_JUGA 15

void inicializar_partida(tpartida *p);
void mostrar_estado_partida(tpartida *p);
void pasar_turno(tpartida *t);
void mostrar_ganador(tpartida p);
void realizar_jugada(tpartida *p, tjugadas *j);
void tirar_carta(tpartida *p, int pos);
void finalizar_partida(tpartida *p);
void inicializar_descartes(tpartida *p);
void recuperar_mazo(tpartida *p); 

#endif




