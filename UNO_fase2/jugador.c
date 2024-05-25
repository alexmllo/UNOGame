#include <stdio.h>
#include "jugador.h"
#include "baraja.h"

/*void me_queda_UNO(tbaraja mazojugador)
{
    cambiar_color_letra(3);
    printf("** UNO **");
    default_attributes();
}*/

void mostrar_jugador(tjugador j, tpartida p, int pos)
{
    printf("%s %d:\n", j.nom, pos);
    
    mostrar_baraja(j.mano,p);
}
