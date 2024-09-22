#include <stdio.h>
#include <time.h>
#include <math.h>

#include <iostream>
using namespace std;

const  int MAX= 5000;
double A[MAX][MAX], x[MAX], y[MAX];

void inicializarA()
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			A[i][j]=i+j;
}
void inicializarX()
{
	for(int i=0;i<MAX;i++)
		x[i]=i;
}
void inicializarY()
{
	for(int i=0;i<MAX;i++)
		y[i]=0;
}


int main()
{
	inicializarA();
	inicializarX();
	
	inicializarY();

	clock_t begin= clock();
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			y[i]+=A[i][j]*x[j];
	clock_t end = clock();

	inicializarY();

	clock_t begin2= clock();
	for(int j=0;j<MAX;j++)
		for(int i=0;i<MAX;i++)
			y[i]+=A[i][j]*x[j];
	clock_t end2 = clock();


double time = (double)(end - begin) / CLOCKS_PER_SEC;
double time2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
cout << "For 1 : " << time << endl;
cout << "For 2 : " << time2 << endl;
}