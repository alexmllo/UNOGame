#ifndef BARAJA_H
#define BARAJA_H

#include "carta.h"
#include "stdlib.h"
#include "time.h"

#define MAX_CARTAS_UNO 108

void anyadir_carta_a_baraja(tcarta c, tbaraja *b);
void inicializar_baraja_con_cartas_uno(tbaraja *c);
void eliminar_carta_de_baraja(int pos, tbaraja *b);
int baraja_esta_vacia(tbaraja c);
int ultima_carta_baraja(tbaraja c);
void me_queda_UNO(tbaraja mazojugador);
void mezclar_baraja(tbaraja *b);
void mostrar_baraja(tbaraja b, tpartida p);
void mostrar_baraja_mazo(tbaraja c, tpartida p);

#endif
