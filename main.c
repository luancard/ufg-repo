#include <stdlib.h>
#include <stdio.h>
#include "rest.h"

int main(){

    menu * new_Menu;
    order * pedido = NULL;
    FILE * Menu;
    int i, n, ncase, ncase2=1,norder=0, p;

    pedido = (order*) calloc(norder, sizeof(order));

    Menu = fopen("menu.txt", "r");
    if (!Menu) exit(1);
    
    fscanf(Menu, "%d%*c", &n);

    new_Menu = (menu*)calloc(n, sizeof(menu));

    for (i = 0; i < n; i++)
    {
        fscanf(Menu, "%[^\n]%*c", new_Menu[i].prato);
        fscanf(Menu, "%f%*c", &(new_Menu[i].price));
    }
    menu_Switch(ncase2);
    ncase2=2;
    scanf("%d", &ncase);
    while (ncase!=3)
    {
        switch (ncase)
        {
        case 1:
            print_Menu(new_Menu, n);
            break;
        case 2:
            norder++;
            pedido = (order*)realloc(pedido, norder*sizeof(order));
            p = make_order(new_Menu, pedido);
            if (p == 0)
            {
                norder--;
                pedido = (order*)realloc(pedido, norder*sizeof(order));
            }
            
            ncase2 = 3;
            break;
        
        default:
            break;
        }

        menu_Switch(ncase2);
        
        scanf("%d", &ncase);
    }
    
    end_Order(pedido, norder);

    printf("\n Sua conta foi gerada no arquivo conta.txt! Muito obrigado pela visita ao Matatabi Coffe!\n");

    fclose(Menu);
    free(new_Menu);
    free(pedido);
    return 0;
}