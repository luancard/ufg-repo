#include "rest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_Switch(int n){

    switch (n)
    {
    case 1:
        printf("Bem vindo ao Matatabi Coffe! Vai ser um prazer recebe-lo! Como posso ajudar?\n(1) Ver cardapio.\n(2) Fazer pedido.\n(3) Sair.\n");
        break;
    case 2:
        printf("\n O que deseja fazer? \n (1) Ver cardapio.\n (2) Fazer pedido.\n (3) Pedir a conta.\n");
        break;
    case 3:
        printf("\n O que deseja fazer? \n (1) Ver cardapio.\n (2) Pedir mais alguma coisa.\n (3) Pedir a conta.\n");
        break;
    default:
        break;
    }
}

void print_Menu(menu new_Menu[], int n){

    int i;

    for (i = 0; i < n; i++)
    {
        printf("(%d) %s ------- %.2f\n", i, new_Menu[i].prato, new_Menu[i].price);
    }
}

void print_Pedidos(order pedido[], int n){

    int i;

    for (i = 0; i < n; i++)
    {
        printf("%dx %s ------- %.2f\n", pedido[i].qnt, pedido[i].prato, pedido[i].price);
    }
}

int make_order(menu new_Menu[], order pedido[]){

    int i, j, k;
    printf("\n Digite o numero do item que deseja pedir:\n");
    scanf("%d", &k);

    i = 0;
    while (pedido[i].price!=0)
    {
        if (strcmp(pedido[i].prato, new_Menu[k].prato)==0)
        {
            break;
        }
        
        i++;
    }
    if (pedido[i].qnt == 0)
    {
        strcpy(pedido[i].prato, new_Menu[k].prato);
        pedido[i].price = new_Menu[k].price;
        pedido[i].qnt++;
        return 1;
    } else {
        pedido[i].price += new_Menu[k].price;
        pedido[i].qnt++;
        return 0;
    }

}

void end_Order(order pedido[], int n){

    FILE * conta;
    float TOTAL=0;
    int i;

    conta = fopen("conta", "w");
    if(!conta) exit(1);

    for ( i = 0; i < n; i++)
    {
        TOTAL += pedido[i].price;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(conta,"%dx %s ------- R$%.2f\n", pedido[i].qnt, pedido[i].prato, pedido[i].price);
    }

    fprintf(conta, "Total: ------- R$%.2f", TOTAL);

    fclose(conta);
}