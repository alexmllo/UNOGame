#include <stdio.h>
#include "jugadas.h"
#include "baraja.h"
#include "carta.h"
#include "azar.h"
#include "jugador.h"

void mostrar_jugadas(tjugadas f,tpartida p)
{
    int i;
    
    cambiar_color_letra(2);
    printf("\nTurno ");
    if(p.Js.turno==0)
    {
        printf("%s: ", p.Js.vjug[0].nom);
    }
    else if(p.Js.turno==1)
    {
        printf("%s 1: ", p.Js.vjug[1].nom);
    }
    else if(p.Js.turno==2)
    {
        printf("%s 2: ", p.Js.vjug[2].nom);
    }
    else if(p.Js.turno==3)
    {
        printf("%s 3: ", p.Js.vjug[3].nom);
    }
    else if(p.Js.turno==4)
    {
        printf("%s 4: ", p.Js.vjug[4].nom);
    }
    default_attributes();
    
    if(p.visible==1)
    {
        printf("Jugadas posibles: ");
    
        for(i=0; i<f.num_jugadas; i++)
        {
            printf("%d(", i);
            mostrar_jugada(f.vjugadas[i],p);
            printf("|) ");
        }
    }
    else
    {
        if(p.Js.turno==0)
        {
            p.visible=1;
            printf("Jugadas posibles: ");
            
            for(i=0; i<f.num_jugadas; i++)
            {
                printf("%d(", i);
                mostrar_jugada(f.vjugadas[i],p);
                printf("|) ");
            }
            p.visible=0;
        }
    }
}

void calcular_jugadas(tcarta descarte, tbaraja b, tjugadas *j)
{
    int i;
    j->num_jugadas=0;
    for(i=0 ; i<b.ncartas ; i++)
    {
        if(descarte.color==b.cartas[i].color || descarte.figura==b.cartas[i].figura)
        {
            anyadir_jugada(j->num_jugadas,b.cartas[i],j);
        }
    }
}

void eliminar_jugadas(tjugadas *j, int pos) //posicion a eliminar//
{
    int i;
    
    for(i=pos ; i<j->num_jugadas-1 ; i++)
    {
        j->vjugadas[i]=j->vjugadas[i+1];
        j->num_jugadas--;
    }
}

int hay_jugada(tcarta mazodescartes, tbaraja mazojugador) //mazo descarte esta en tpartida//
{
    int jugadas=0, i=0;
    
    while(i<mazojugador.ncartas && jugadas==0)
    {
        if(mazodescartes.color==mazojugador.cartas[i].color || mazodescartes.figura==mazojugador.cartas[i].figura)
        {
            jugadas=1;
        }
        i++;
    }
    return jugadas;  //jugadas=0--> no hay  jugadas!=0--> si hay//
}

int seleccionar_jugada(tjugadas numjugadas, tpartida p)
{
    int opc;
    
    inicializar_azar();
    
    if(p.Js.turno==0)
    {
        printf("\nQue carta tiras?   [0-%d]: ", numjugadas.num_jugadas-1);
        scanf("%d%*c", &opc);
    }
    else
    {
        opc=numero_al_azar(numjugadas.num_jugadas);
    }
    
    return opc;
}

void anyadir_jugada(int pos, tcarta c, tjugadas *j)
{
    j->vjugadas[pos].carta=c;
    j->num_jugadas++;
}
