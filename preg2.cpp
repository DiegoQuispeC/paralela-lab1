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

void multmat3()
{
    clock_t begin= clock();
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)     
            for(int k=0; k<MAX; k++)
                C[i][j]= C[i][j]+A[i][k]*B[k][j];

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<"Matriz cuadrada de "<<MAX<<"x"<<MAX<<" con 3 bucles : ";	
    cout << time_spent << endl;
}

int main()
{
	inicializarAB();
	inicializarC();
	
    multmat3();


}