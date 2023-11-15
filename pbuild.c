#include "poly.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[]){

    FILE * poly;
    Poly p1;
    p1.coef = NULL;
    int i;

    p1.id[0] = 'p';
    p1.id[1] = 'o';
    p1.id[2] = 'l';
    p1.id[3] = 'y';

    poly = fopen(argv[2],"wb");

    if (!poly)
    {
        printf("\n --- Erro na Matrix --- \n");
        exit(1);
    }

    p1.p = get_Expo(argv[1]);

    p1.coef = (double*) calloc((p1.p)+1, sizeof(double));

    build_Polynomial(p1.coef, argv[1]);
    
    fwrite(p1.id, sizeof(char), 4, poly);
    fwrite(&(p1.p), sizeof(int), 1, poly);
    fwrite(p1.coef, sizeof(double), (p1.p)+1, poly);

    fclose(poly);
    free(p1.coef);
    return 0;
}