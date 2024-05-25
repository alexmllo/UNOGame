#include <stdio.h>
#include "partida.h"

void inicializar_partida(tpartida *p)
{
    p->Js.turno=0;
    p->fin_partida=0;
    p->sentido=0;  //horario
    p->especial=0;
    p->primera_jugada=0;
    
    inicializar_baraja_con_cartas_uno(&p->mazo);
    mezclar_baraja(&p->mazo);
    
    inicializar_descartes(p);
    
    cambiar_color_letra(2);
    printf("\n\t       *    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  *                                               \n");
    printf("\t\t\t  __    __    ___      _     ________        \n ");
    printf("\t\t\t |  || |  || |   \\    | ||  /        \\        \n");
    printf("\t\t\t |  || |  || |    \\   | || /    ___   \\       \n");
    printf("\t\t\t |  || |  || |  |\\ \\  | || |   ||  |  ||       \n");
    printf("\t\t\t |  || |  || |  ||\\ \\ | || |   ||__|  ||           \n");
    printf("\t\t\t \\   \\_|  || |  || \\ \\| || \\          //               \n");
    printf("\t\t\t  \\______//  |__||  \\___||  \\________//            \n\n");
    printf("\t       *    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  *\n\n");
    default_attributes();
    
    inicializar_jugadores(&p->Js,&p->mazo);
    
    do
    {
        printf("\t\t--> Quieres ejecutar en modo COMPROVACION? [si=1/no=0]: "); //1 muestra todas
        scanf("%d",&p->visible);
    }while(p->visible<0 || p->visible>1);
}

void mostrar_estado_partida(tpartida *p)
{
    int i;
    
    if(p->mazo.ncartas==0)
    {
        recuperar_mazo(p);
    }
    
    if(p->visible==0)
    {
        if(p->fin_partida==0)
        {
            if(p->descarte.cartas[p->descarte.ncartas-1].figura==10 && p->fin_partida!=1 && p->especial==0)
            {
                //+2
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                if(p->sentido==0)
                {
                    if(p->Js.turno<=p->Js.n_jug-1)
                    {
                        p->Js.turno++;
                    }
                    if(p->Js.turno>p->Js.n_jug-1)
                    {
                        p->Js.turno=0;
                    }
                }
                else
                {
                    if(p->Js.turno>=0)
                    {
                        p->Js.turno--;
                    }
                    if(p->Js.turno<0)
                    {
                        p->Js.turno=p->Js.n_jug-1;
                    }
                }
            }
            //+4
            if(p->descarte.cartas[p->descarte.ncartas-1].figura==14 && p->fin_partida!=1 && p->especial==0)
            {
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                if(p->sentido==0)
                {
                    if(p->Js.turno<=p->Js.n_jug-1)
                    {
                        p->Js.turno++;
                    }
                    if(p->Js.turno>p->Js.n_jug-1)
                    {
                        p->Js.turno=0;
                    }
                }
                else
                {
                    if(p->Js.turno>=0)
                    {
                        p->Js.turno--;
                    }
                    if(p->Js.turno<0)
                    {
                        p->Js.turno=p->Js.n_jug-1;
                    }
                }
            }
        }
        //saltar turno
        if(p->descarte.cartas[p->descarte.ncartas-1].figura==12 && p->sentido==0 && p->especial==0)
        {
            if(p->Js.turno==p->Js.n_jug-1)
            {
                p->Js.turno=1;
            }
            else
            {
                p->Js.turno++;
            }
        }
        else if(p->descarte.cartas[p->descarte.ncartas-1].figura==12 && p->sentido==1 && p->especial==0)
        {
            if(p->Js.turno==0)
            {
                p->Js.turno=p->Js.n_jug-1; //2 ?
            }
            else
            {
                p->Js.turno--;
            }
        }
        p->especial=0;
            
        printf("\nMazo: \n");
        mostrar_baraja_mazo(p->mazo,*p);
    
        p->visible=1;
        printf("Mazo Descartes:\n");
        mostrar_carta(p->descarte.cartas[p->descarte.ncartas-1], *p);
        printf("|");
        printf("(%d) Sentido: ",p->descarte.ncartas);
        if(p->sentido==0)
        {
            cambiar_color_letra(4);
            printf("HORARIO\n");
            default_attributes();
        }
        else
        {
            cambiar_color_letra(4);
            printf("ANTIHORARIO\n");
            default_attributes();
        }
    
        printf("%s:\n",p->Js.vjug[0].nom);
        
        mostrar_baraja(p->Js.vjug[0].mano,*p);
    
        p->visible=0;
        mostrar_jugadores(p->Js, *p);
    }
    else
    {
        if(p->fin_partida==0)
        {
            //+2
            if(p->descarte.cartas[p->descarte.ncartas-1].figura==10 && p->fin_partida!=1 && p->especial==0)
            {
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                if(p->sentido==0)
                {
                    if(p->Js.turno<=p->Js.n_jug-1)
                    {
                        p->Js.turno++;
                    }
                    if(p->Js.turno>p->Js.n_jug-1)
                    {
                        p->Js.turno=0;
                    }
                }
                else
                {
                    if(p->Js.turno>=0)
                    {
                        p->Js.turno--;
                    }
                    if(p->Js.turno<0)
                    {
                        p->Js.turno=p->Js.n_jug-1;
                    }
                }
            }
            
            //+4
            if(p->descarte.cartas[p->descarte.ncartas-1].figura==14 && p->fin_partida!=1 && p->especial==0)
            {
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                anyadir_carta_a_baraja(p->mazo.cartas[0], &p->Js.vjug[p->Js.turno].mano);
                eliminar_carta_de_baraja(0, &p->mazo);
                    
                if(p->sentido==0)
                {
                    if(p->Js.turno<=p->Js.n_jug-1)
                    {
                        p->Js.turno++;
                    }
                    if(p->Js.turno>p->Js.n_jug-1)
                    {
                        p->Js.turno=0;
                    }
                }
                else
                {
                    if(p->Js.turno>=0)
                    {
                        p->Js.turno--;
                    }
                    if(p->Js.turno<0)
                    {
                        p->Js.turno=p->Js.n_jug-1;
                    }
                }
            }
        }
        //saltar turno
        if(p->descarte.cartas[p->descarte.ncartas-1].figura==12 && p->sentido==0 && p->especial==0)
        {
            if(p->Js.turno==p->Js.n_jug-1)
            {
                p->Js.turno=0;
            }
            else
            {
                p->Js.turno++;
            }
        }
        else if(p->descarte.cartas[p->descarte.ncartas-1].figura==12 && p->sentido==1 && p->especial==0)
        {
            if(p->Js.turno==0)
            {
                p->Js.turno=p->Js.n_jug-1;
            }
            else
            {
                p->Js.turno--;
            }
        }
        p->especial=0;
                    
        printf("\nMazo:\n");
        mostrar_baraja_mazo(p->mazo,*p);
            
        printf("Mazo Descartes:\n");
        mostrar_carta(p->descarte.cartas[p->descarte.ncartas-1],*p);
        printf("|");
        printf("(%d) Sentido: ",p->descarte.ncartas);
        if(p->sentido==0)
        {
            cambiar_color_letra(4);
            printf("HORARIO\n");
            default_attributes();
        }
        else
        {
            cambiar_color_letra(4);
            printf("ANTIHORARIO\n");
            default_attributes();
        }
            
        printf("%s:\n",p->Js.vjug[0].nom);
            
        mostrar_baraja(p->Js.vjug[0].mano,*p);
        mostrar_jugadores(p->Js, *p);
    }
}

void pasar_turno(tpartida *t)
{
    if(t->sentido==1)
    {
        if(t->Js.turno>=0)
        {
            t->Js.turno--;
        }
        if(t->Js.turno<0)
        {
            t->Js.turno=t->Js.n_jug-1;
        }
    }
    
    else
    {
        if(t->Js.turno<=t->Js.n_jug-1)
        {
            t->Js.turno++;
        }
        if(t->Js.turno>t->Js.n_jug-1)
        {
            t->Js.turno=0;
        }
    }
    
    if(t->primera_jugada==1)
    {
        esperar();
    }
    t->primera_jugada=1;
}

void mostrar_ganador(tpartida p)
{
    int vacio, i, j;
    
    esperar();
    
    mostrar_estado_partida(&p);
    
    cambiar_color_letra(2);
    printf("     \n\t\t\t  ===>>> FIN PARTIDA <<<===\n");
    default_attributes();
    p.visible=1;
    mostrar_estado_partida(&p);
    
    for(i=0 ; i<p.Js.n_jug ; i++)
    {
        if(p.Js.vjug[i].mano.ncartas==0)
        {
            if(p.Js.turno==0)
            {
                cambiar_color_letra(1);
                printf("    \n\n\t\t===>>> HA GANADO %s. ¡FELICIDADES! <<<===\n\n\n ",p.Js.vjug[i].nom);
                default_attributes();
            }
            else
            {
                cambiar_color_letra(1);
                printf("    \n\t\t===>>> HA GANADO %s %d. ¡FELICIDADES! <<<===\n\n\n ", p.Js.vjug[i].nom, i);
                default_attributes();
            }
        }
    }
}

void realizar_jugada(tpartida *p, tjugadas *j)
{
    int jugadas=0, opcion, i=0, encontrado=0, jug=0, color;
    jugadas=hay_jugada(p->descarte.cartas[p->descarte.ncartas-1],p->Js.vjug[p->Js.turno].mano);

    if(jugadas!=0)
    {
        calcular_jugadas(p->descarte.cartas[p->descarte.ncartas-1], p->Js.vjug[p->Js.turno].mano, j);
        mostrar_jugadas(*j,*p);
 
        opcion=seleccionar_jugada(*j, *p);
        
        printf("Tira: ");
        if(p->visible==1)
        {
            mostrar_carta(j->vjugadas[opcion].carta, *p);
        }
        else
        {
            p->visible=1;
            mostrar_carta(j->vjugadas[opcion].carta, *p);
            p->visible=0;
        }
        
        while(i<p->Js.vjug[p->Js.turno].mano.ncartas && encontrado==0)
        {
        if(p->Js.vjug[p->Js.turno].mano.cartas[i].color==j->vjugadas[opcion].carta.color && p->Js.vjug[p->Js.turno].mano.cartas[i].figura==j->vjugadas[opcion].carta.figura)
            {
                encontrado=1;
            }
            else
            {
                i++;
            }
        }
        tirar_carta(p,i);
        eliminar_jugadas(j,0);
        
        if(p->descarte.cartas[p->descarte.ncartas-1].figura==11 && p->sentido==0)
        {
            p->sentido=1;
        }
        else if(p->descarte.cartas[p->descarte.ncartas-1].figura==11 && p->sentido==1)
        {
            p->sentido=0;
        }
        
        if(p->descarte.cartas[p->descarte.ncartas-1].figura!=13 && p->descarte.cartas[p->descarte.ncartas-1].figura!=14)
        {
            printf("|\n");
        }
        else if(p->descarte.cartas[p->descarte.ncartas-1].figura==13 || p->descarte.cartas[p->descarte.ncartas-1].figura==14)
        {
            printf("|");
            color=preguntar_color();
            
            p->descarte.cartas[p->descarte.ncartas-1].color=color;
        }
    }
    else
    {
        cambiar_color_letra(2);
        printf("\nTurno ");
        if(p->Js.turno==0)
        {
            printf("%s: ", p->Js.vjug[0].nom);
        }
        else if(p->Js.turno==1)
        {
            printf("%s 1: ", p->Js.vjug[1].nom);
        }
        else if(p->Js.turno==2)
        {
            printf("%s 2: ", p->Js.vjug[2].nom);
        }
        else if(p->Js.turno==3)
        {
            printf("%s 3: ", p->Js.vjug[3].nom);
        }
        else if(p->Js.turno==4)
        {
            printf("%s 4: ", p->Js.vjug[4].nom);
        }
        default_attributes();
        
        printf("Coge del mazo: ");
        anyadir_carta_a_baraja(p->mazo.cartas[0],&p->Js.vjug[p->Js.turno].mano);
        eliminar_carta_de_baraja(0,&p->mazo);
        if(p->Js.turno==0)
        {
            if(p->visible==0)
            {
                p->visible=1;
                mostrar_carta(p->Js.vjug[p->Js.turno].mano.cartas[p->Js.vjug[p->Js.turno].mano.ncartas-1],*p);
                printf("| ");
                p->visible=0;
            }
            else
            {
                mostrar_carta(p->Js.vjug[p->Js.turno].mano.cartas[p->Js.vjug[p->Js.turno].mano.ncartas-1],*p);
                printf("|");
            }
        }
        else
        {
            mostrar_carta(p->Js.vjug[p->Js.turno].mano.cartas[p->Js.vjug[p->Js.turno].mano.ncartas-1],*p);
                printf("|");
        }
        jug=hay_jugada(p->descarte.cartas[p->descarte.ncartas-1],p->Js.vjug[p->Js.turno].mano);
        
        if(jug!=0)
        {
            printf(" Tira: ");
            if(p->visible==0)
            {
                p->visible=1;
                mostrar_carta(p->Js.vjug[p->Js.turno].mano.cartas[p->Js.vjug[p->Js.turno].mano.ncartas-1], *p);
                p->visible=0;
            }
            else
            {
                mostrar_carta(p->Js.vjug[p->Js.turno].mano.cartas[p->Js.vjug[p->Js.turno].mano.ncartas-1], *p);
            }
            i=0;
            
            tirar_carta(p,p->Js.vjug[p->Js.turno].mano.ncartas-1);
            
            if(p->descarte.cartas[p->descarte.ncartas-1].figura==11 && p->sentido==0)
            {
                p->sentido=1;
            }
            else if(p->descarte.cartas[p->descarte.ncartas-1].figura==11 && p->sentido==1)
            {
                p->sentido=0;
            }
            
            if(p->descarte.cartas[p->descarte.ncartas-1].figura!=13 && p->descarte.cartas[p->descarte.ncartas-1].figura!=14)
            {
                printf("|\n");
            }
            else if(p->descarte.cartas[p->descarte.ncartas-1].figura==13 || p->descarte.cartas[p->descarte.ncartas-1].figura==14)
            {
                printf("|");
                color=preguntar_color();
                
                p->descarte.cartas[p->descarte.ncartas-1].color=color;
            }
        }
        else
        {
            printf(" Ha pasado\n");
            
            if(p->primera_jugada==0)
            {
                esperar();
            }
            
            if(p->descarte.cartas[p->descarte.ncartas-1].figura>9 && p->descarte.cartas[p->descarte.ncartas-1].figura<14)
            {
                p->especial=1;
            }
        }
    }
}

void tirar_carta(tpartida *p, int pos)
{
    anyadir_carta_a_baraja(p->Js.vjug[p->Js.turno].mano.cartas[pos], &p->descarte);
    eliminar_carta_de_baraja(pos, &p->Js.vjug[p->Js.turno].mano);
}

void finalizar_partida(tpartida *p)
{
    int vacio=0 ,i=0;
    
    while(vacio!=1 && i<p->Js.n_jug)
    {
        vacio=baraja_esta_vacia(p->Js.vjug[i].mano);
        i++;
    }
    
    if(vacio==1)
    {
        p->fin_partida=1;
    }
}

void inicializar_descartes(tpartida *p)
{
    p->descarte.ncartas=0;
    
    anyadir_carta_a_baraja (p->mazo.cartas[0],&p->descarte);
    
    while(p->descarte.cartas[p->descarte.ncartas-1].figura==10 || p->descarte.cartas[p->descarte.ncartas-1].figura==11 || p->descarte.cartas[p->descarte.ncartas-1].figura==12 || p->descarte.cartas[p->descarte.ncartas-1].figura==13 || p->descarte.cartas[p->descarte.ncartas-1].figura==14)
    {
        anyadir_carta_a_baraja(p->descarte.cartas[0], &p->mazo);
        eliminar_carta_de_baraja(0, &p->descarte);
        
        anyadir_carta_a_baraja (p->mazo.cartas[0],&p->descarte);
    }
    eliminar_carta_de_baraja(0,&p->mazo);
}

void recuperar_mazo(tpartida *p) //mazo descarte//
{
    int i;
    
    for(i=0 ; i<p->descarte.ncartas-1 ; i++)
    {
        anyadir_carta_a_baraja(p->descarte.cartas[0], &p->mazo);
        eliminar_carta_de_baraja(0, &p->descarte);
    }
}
