#include <stdio.h>
#include "jugadores.h"
#include "jugador.h"

void mostrar_jugadores(tjugadores d,tpartida p)
{
    int i;
    
    for(i=1 ; i<d.n_jug ; i++)
    {
        mostrar_jugador(d.vjug[i],p, i);
    }
}

void repartir_cartas_jugadores(tjugadores *jug, tbaraja *b)
{
    int i, j;
    
    for(i=0 ; i<jug->n_jug ; i++)
    {
        for(j=0;j<7;j++)
        {
            jug->vjug[i].mano.cartas[j]=b->cartas[j];
            eliminar_carta_de_baraja(0,b);  //*?
        }
        jug->vjug[i].mano.ncartas=7;
    }
}

void inicializar_jugadores(tjugadores *k,tbaraja *b)
{
    int i=0, j;
    char a;
    
    do
    {
        printf("\t\t--> Cuantos jugadores?  [3-5]: ");
        scanf("%d%*c", &k->n_jug);
    }while(k->n_jug<3 || k->n_jug>5);
    
    printf("\t\t--> Tu nombre? ");
    
    scanf("%c", &a);
    while(a!='\n' && i<MAX_NOM)
    {
        k->vjug[0].nom[i]=a;
        i++;
        scanf("%c", &a);
    }
    k->vjug[0].nom[i]='\0';
    
    for(j=1 ; j<k->n_jug ; j++)
    {
        k->vjug[j].nom[0]='R';
        k->vjug[j].nom[1]='o';
        k->vjug[j].nom[2]='b';
        k->vjug[j].nom[3]='o';
        k->vjug[j].nom[4]='t';
        k->vjug[j].nom[5]='\0';
    }
    repartir_cartas_jugadores(k,b);
}
