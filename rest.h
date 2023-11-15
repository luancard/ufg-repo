#ifndef REST_H
#define REST_H

#define N 64

typedef struct
{
    char prato[N];
    float price;
    int qnt;
} order;

typedef struct
{
    char prato[N];
    float price;
} menu;

void menu_Switch(int n);
void print_Menu(menu new_Menu[], int n);
void print_Pedidos(order pedido[], int n);
int make_order(menu new_Menu[], order pedido[]);
void end_Order(order pedido[], int n);

#endif