#ifndef CARTA_H
#define CARTA_H

#include "colores.h"

#define MAX_CARTAS_UNO 108
#define MAX_NOM 20
#define MAX_JUGA 15

typedef struct
{
    int color;
    int figura;
}tcarta;

typedef struct
{
    tcarta cartas[MAX_CARTAS_UNO];
    int ncartas;
}tbaraja;

typedef struct
{
    char nom[MAX_NOM];
    tbaraja mano;
}tjugador;

typedef struct
{
    tjugador vjug[MAX_JUGA];
    int n_jug;
    int turno;
}tjugadores;

typedef struct
{
    tjugadores Js;
    tbaraja mazo;
    tbaraja descarte;
    int visible;
    int sentido;
    int fin_partida;
    int especial;
    int primera_jugada;
}tpartida;

tcarta inicializar_carta(int color, int figura);
void mostrar_carta(tcarta c, tpartida p);
int se_puede_tirar(tcarta c, tcarta descarte);

#endif
