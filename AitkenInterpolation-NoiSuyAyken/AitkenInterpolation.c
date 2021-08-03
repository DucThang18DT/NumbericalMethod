/*-----------------------------------------------------------------*-
					AitkenInterpolation.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Descreption
-*-----------------------------------------------------------------*-
	calculate the value of the function use Aitken Interpolation.

 * Enter:
 	N - max index of number sequence
	xi - value of x at index i
	yi - value of y at index i
	c - value at which to calculate the function value 
 * Result: 
 	value of funtion at c.
-*-----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void input(float Fx[][20], int *N, float *c){
	printf("Enter N, c: ");
	scanf("%d%f", N,c);
	int i,j;
	for (i = 0; i <= *N; i++){
		printf("Enter x[%d]: ", i);
		scanf("%f", &Fx[0][i]);
	}
	for (i = 0; i <= *N; i++){
		printf("Enter y[%d]: ", i);
		scanf("%f", &Fx[1][i]);
	}
}

void calculate(float Fx[][20], int N, float c){
	float w = 1, Sum = 0,s;
	int i,j;
	for (i = 0; i<=N; i++){
		s = c-Fx[0][i];
		w *= s;
		for (j = 0; j<=N; j++)
			if (i != j) s*= (Fx[0][i] - Fx[0][j]);
		Sum += Fx[1][i]/s;
	}
	printf("\nResult = %f",Sum*w);
}

int main(){
	int N;
	float Fx[2][20],c;
	input(Fx, &N,&c);
	calculate(Fx, N,c);
}

/*------------------------- END FILE ------------------------------*/