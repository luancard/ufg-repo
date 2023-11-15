#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    FILE * poly;
    Poly p1;
    p1.coef = NULL;

    poly = fopen(argv[1], "rb");

    if (!poly)
    {
        printf("\n --- Erro na Matrix --- \n");
        exit(1);
    }

    fread(p1.id, sizeof(char), 4, poly);
    fread(&(p1.p), sizeof(int), 1, poly);

    p1.coef = (double*) calloc((p1.p)+1, sizeof(double));
    
    fread(p1.coef, sizeof(double), (p1.p)+1, poly);

    print_Polynomial((p1.p)+1, p1.coef);

    fclose(poly);
    free(p1.coef);
    return 0;
}
