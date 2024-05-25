#include <stdio.h>
#include "partida.h"

int main()
{
    tpartida p;
    tjugadas j;
    
    inicializar_partida(&p);
    
    while(p.fin_partida==0)
    {
        mostrar_estado_partida(&p);
        realizar_jugada(&p, &j);
        finalizar_partida(&p);
        if(p.fin_partida==0)
        {
            pasar_turno(&p);
        }
    }
    mostrar_ganador(p);
}
