#ifndef POLY_H
#define POLY_H

#define ID_SIZE 4
typedef struct {
	char id[ID_SIZE];
	int p;
	double * coef;
} Poly;

int get_Expo( char * p );

int get_newExpo ( int nA, int nB );

void build_Polynomial(double poly[], char * polynomial);

void print_Polynomial(int n, double coef[]);

void sum_Polynomial(double new_Poly[], double polyA[], int nA, double polyB[], int nB);

void sub_Polynomial(double new_Poly[], double polyA[], int nA, double polyB[], int nB);


#endif