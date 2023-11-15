#include <stdio.h>
#include <stdlib.h>

#include "poly.h"


int get_Expo( char * p ){
    int expo=0, ex;
    double coef;
    int r, n, nn;
    char c;

    nn = 0;
    while(1){
        r = sscanf(p+nn," %lf x ^ %d %n",&coef, &ex,&n);
        if (ex>expo)
        {
            expo = ex;
        }
        if(r == 0 || r == EOF) 
            break;
        nn += n;

        r = sscanf(p+nn,"%c %n",&c,&n);
        if(r == EOF || r == 0)
            break;
        nn += n;
    }
    return expo;
}

void build_Polynomial(double poly[], char * polynomial){

    char c;
    int r, n, nn, expo, i;
    double coef;
    double sinal = 1.0;

    nn = 0;
    while(1){
        r = sscanf(polynomial+nn," %lf x ^ %d %n",&coef, &expo,&n);
        if(r == 0 || r == EOF) 
            break;
        nn += n;

        poly[expo] = sinal*coef;

        r = sscanf(polynomial+nn,"%c %n",&c,&n);
        if(r == EOF || r == 0)
            break;
        nn += n;
    
        if(c == '-')
            sinal = -1.0;
        else
            sinal = 1.0;
    }
}

void print_Polynomial(int n, double coef[]){

    int cont=0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (coef[i]!=0)
        {
            if (i==0)
            {
                if (coef[i]-(int)coef[i]!=0)
                {
                    printf("%.2lf", coef[i]);
                } else {
                    printf("%.0lf", coef[i]);
                }
                cont++;
            } else if (cont==0)
            {
                if (coef[i]-(int)coef[i]!=0)
                {   
                    printf("%.2lfx^%d", coef[i], i);
                } else {
                    if (coef[i]==1|| coef[i]==-1)
                    {
                        printf("x^%d", i);
                    } else {
                        printf("%.0lfx^%d", coef[i], i);
                    }
                }
                cont++;
            } else if (cont != 0 && coef[i]>0)
            {
                if (coef[i]-(int)coef[i]!=0)
                {
                    printf("+%.2lfx^%d", coef[i], i);
                } else {
                    if (coef[i]==1|| coef[i]==-1)
                    {
                        printf("+x^%d", i);
                    } else {
                        printf("+%.0lfx^%d", coef[i], i);
                    }
                }
                cont++;
            } else if (cont != 0 && coef[i]<0)
            {
                if (coef[i]-(int)coef[i]!=0)
                {
                    printf("%.2lfx^%d", coef[i], i);
                } else {
                    if (coef[i]==1|| coef[i]==-1)
                    {
                        printf("-x^%d", i);
                    } else {
                        printf("%.0lfx^%d", coef[i], i);
                    }
                }
                cont++;
            }
        }
    }
    printf("\n");
}

int get_newExpo ( int nA, int nB ){

    if (nA>nB)
    {
        return nA;
    } else {
        return nB;
    }
}

void sum_Polynomial(double new_Poly[], double polyA[], int nA, double polyB[], int nB){

    int i, n;
    if (nA>nB)
    {
        n = nA+1;

        for ( i = 0; i < n; i++)
        {
            if (i<nB+1)
            {
                new_Poly[i] = polyA[i] + polyB[i];
            } else
            {
                new_Poly[i] = polyA[i];
            }
        }
    } else {
        n = nB+1;
        for ( i = 0; i < n; i++)
        {
            if (i<nA+1)
            {
                new_Poly[i] = polyA[i] + polyB[i];
            } else
            {
                new_Poly[i] = polyB[i];
            }
        }
    }
}

void sub_Polynomial(double new_Poly[], double polyA[], int nA, double polyB[], int nB){

    int i, n;
    if (nA>nB)
    {
        n = nA+1;

        for ( i = 0; i < n; i++)
        {
            if (i<nB+1)
            {
                new_Poly[i] = polyA[i] - polyB[i];
            } else
            {
                new_Poly[i] = polyA[i];
            }
        }
    } else {
        n = nB+1;
        for ( i = 0; i < n; i++)
        {
            if (i<nA+1)
            {
                new_Poly[i] = polyA[i] - polyB[i];
            } else
            {
                new_Poly[i] = (-1.0)*polyB[i];
            }
        }
    }

}