#include <stdio.h>
#include "jugador.h"
#include "baraja.h"

void mostrar_jugador(tjugador j, tpartida p, int pos)
{
    printf("%s %d:\n", j.nom, pos);
    
    mostrar_baraja(j.mano,p);
}
