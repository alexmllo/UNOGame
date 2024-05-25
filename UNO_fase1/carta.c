#include <stdio.h>
#include "carta.h"

tcarta inicializar_carta(int color, int figura)
{
    tcarta c;
    
    c.color=color;
    c.figura=figura;
    
    return c;
}

void mostrar_carta(tcarta c, tpartida p)
{
    if(p.visible==1)
    {
        switch (c.figura)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                printf("|");
                cambiar_color_fondo(c.color);
                printf(" %d ", c.figura);
                default_attributes();
                break;
        }
    }
    else
    {
        printf("|");
        cambiar_color_fondo(0);
        cambiar_color_letra(2);
        printf("UNO");
        default_attributes();
    }
}

int se_puede_tirar(tcarta c, tcarta descarte)
{
    int se_puede_tirar=0;
    
    if(c.figura==descarte.figura || c.color==descarte.color)
    {
        se_puede_tirar=1;
    }
    return se_puede_tirar;
}
