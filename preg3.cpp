#include <stdio.h>
#include <time.h>
#include <math.h>

#include <iostream>
using namespace std;

const  int MAX= 2000;
double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

void inicializarAB()
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
        {
            A[i][j]=i+j;
            B[i][j]=(i+j)*3;
        }		
}

void inicializarC()
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
            C[i][j]=0;
}


void multmat6()
{
	int BlockS=200;
	clock_t begin= clock();
	for (int i1 = 0; i1 < MAX ; i1 += BlockS)
		for (int j1 = 0; j1 < MAX ; j1 += BlockS)
			for ( int k1 = 0; k1 <MAX ; k1 += BlockS)
				for (int i = i1; i<i1+BlockS&&i<MAX ;i++)
					for	(int j=j1; j<j1+BlockS&&j<MAX ;j++)
						for	(int k=k1; k<k1+BlockS&&k<MAX ;k++)
							C[i][j] += A[i][k]*B[k][j];
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<"Matriz cuadrada de "<<MAX<<"x"<<MAX<<" con 6 bucles y "<<BlockS<<" bloques: ";	
	cout << time_spent << endl;
}
int main()
{
	inicializarAB();
	inicializarC();
	
    multmat6();
}