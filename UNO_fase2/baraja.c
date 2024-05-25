#include <stdio.h>
#include "baraja.h"

void inicializar_baraja_con_cartas_uno(tbaraja *c)
{
    int k=0, a=0, j, i;

    for(j=1 ; j<=4 ; j++)
    {
        a=0;
        while(a!=2)
        {
            for(i=1 ; i<=9 ; i++)
            {
                c->cartas[k]=inicializar_carta(j, i); //j=color i=figura//
                k++;
            }
            a++;
        }

        c->cartas[k]=inicializar_carta(j, 0);
        k++;
        
        a=0;
        while(a!=2)
        {
            for(i=10 ; i<13 ; i++)
            {
                c->cartas[k]=inicializar_carta(j, i);
                k++;
            }
            a++;
        }
    }

    a=0;
    while(a!=4)
    {
        for(i=13 ; i<15 ; i++)
        {
            c->cartas[k]=inicializar_carta(0, i);
            k++;
        }
        a++;
    }
    c->ncartas=108;
}

void anyadir_carta_a_baraja(tcarta c, tbaraja *b)
{
    b->cartas[b->ncartas]=c;
    b->ncartas++;
}

void eliminar_carta_de_baraja(int pos, tbaraja *b)
{
    int i;
    
    for(i=pos ; i<b->ncartas-1 ; i++)
    {
        b->cartas[i]=b->cartas[i+1];
    }
    b->ncartas--;
}

int baraja_esta_vacia(tbaraja c)
{
    int baraja_esta_vacia=0;
    
    if(c.ncartas==0)
    {
        baraja_esta_vacia++;
    }
    return baraja_esta_vacia;   /*si devuleve un 0 no esta vacia si devuelve un 1 esta vacia*/
}

int ultima_carta_baraja(tbaraja c)
{
    int ultima_carta_baraja=0;
    
    if(c.ncartas==1)
    {
        ultima_carta_baraja++;
    }
    return ultima_carta_baraja;   /*si devuleve un 0 no queda una carta si devuelve un 1 queda una carta*/
}

void mezclar_baraja(tbaraja *b)
{
    tcarta aux={0,0};
    
    int n1, n2, i;
    
    srand(time(NULL));
    
    for(i=0 ; i<108 ; i++)
    {
        n1=rand() % 108;
        n2=rand() % 108;
        
        
        aux=b->cartas[n1];
        b->cartas[n1]=b->cartas[n2];
        b->cartas[n2]=aux;
    }
}

void mostrar_baraja(tbaraja c, tpartida p)
{
    int i;
    
    if(c.ncartas!=0)
    {
        for(i=0 ; i<c.ncartas ; i++)
        {
            mostrar_carta(c.cartas[i], p);
        }
        
        if(c.ncartas==1)
        {
            printf("|");
            me_queda_UNO(p.Js.vjug[0].mano);
        }
        else
        {
            printf("|\n");
        }
    }
    else
    {
        printf("\n");
    }
}

void me_queda_UNO(tbaraja mazojugador)
{
    cambiar_color_letra(3);
    printf("** UNO **\n");
    default_attributes();
}

void mostrar_baraja_mazo(tbaraja c, tpartida p)
{
    int i;
    if(p.visible==1)
    {
        if(c.ncartas<20)
        {
            for(i=0 ; i<c.ncartas ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        
        else if(c.ncartas==20)
        {
            for(i=0 ; i<c.ncartas ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
        }
        else if(c.ncartas>20 && c.ncartas<40)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<c.ncartas ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        else if(c.ncartas==40)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
        }
        else if(c.ncartas>40 && c.ncartas<50)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=40 ; i<c.ncartas ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        else if(c.ncartas==50)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=40 ; i<50 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        else if(c.ncartas>50 && c.ncartas<60)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=40 ; i<c.ncartas ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        else if(c.ncartas==60)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=40 ; i<60 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        else if(c.ncartas>60 && c.ncartas<80)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=40 ; i<60 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=60 ; i<c.ncartas ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        
        else if(c.ncartas==80)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=40 ; i<60 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=60 ; i<80 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
        
        else if(c.ncartas>80 && c.ncartas<100)
        {
            for(i=0 ; i<20 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=20 ; i<40 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=40 ; i<60 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=60 ; i<80 ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n ---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
            
            for(i=80 ; i<c.ncartas ; i++)
            {
                mostrar_carta(c.cartas[i], p);
            }
            printf("|\n");
        }
    }
    else
    {
        mostrar_carta(c.cartas[0], p);
        printf("|(%d) %c\n", c.ncartas, p.sentido);
    }
}
