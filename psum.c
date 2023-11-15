#include "poly.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){

    FILE * polyA;
    FILE * polyB;
    FILE * new_Poly;
    Poly pA, pB, new_P;

    pA.coef = NULL;
    pB.coef = NULL;
    new_P.coef = NULL;

    polyA = fopen(argv[1], "rb");

    if (!polyA)
    {
        printf("\n --- Erro na Matrix --- \n");
        exit(1);
    }

    fread(pA.id, sizeof(char), 4, polyA);
    fread(&(pA.p), sizeof(int), 1, polyA);

    pA.coef = (double*) calloc((pA.p)+1, sizeof(double));
    
    fread(pA.coef, sizeof(double), (pA.p)+1, polyA);

    fclose(polyA);

    polyB = fopen(argv[2], "rb");

    if (!polyB)
    {
        printf("\n --- Erro na Matrix --- \n");
        exit(1);
    }

    fread(pB.id, sizeof(char), 4, polyB);
    fread(&(pB.p), sizeof(int), 1, polyB);

    pB.coef = (double*) calloc((pB.p)+1, sizeof(double));
    
    fread(pB.coef, sizeof(double), (pB.p)+1, polyB);

    fclose(polyB);



    new_Poly = fopen(argv[3], "wb");

    if (!new_Poly)
    {
        printf("\n --- Erro na Matrix --- \n");
        exit(1);
    }

    new_P.p = get_newExpo(pA.p, pB.p);

    new_P.coef = (double*) calloc((new_P.p)+1, sizeof(double));

    sum_Polynomial(new_P.coef, pA.coef, pA.p, pB.coef, pB.p);

    fwrite(new_P.id, sizeof(char), 4, new_Poly);
    fwrite(&(new_P.p), sizeof(int), 1, new_Poly);
    fwrite(new_P.coef, sizeof(double), (new_P.p)+1, new_Poly);

    fclose(new_Poly);
    free(pA.coef);
    free(pB.coef);
    free(new_P.coef);
    return 0;
}