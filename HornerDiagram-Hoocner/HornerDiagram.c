/*-----------------------------------------------------------------*-
						HornerDiagram.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Description
-*-----------------------------------------------------------------*-
	calculate the value of the function use Horner diagram.

 * Enter:
 	N - highest degree of the equation
	ai - coefficients of the equation
	c - value at which to calculate the function value 
 * Result: 
 	value of funtion at c.
-*-----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void input(float A[], int *n, float *c){
	printf("\nEnter n, c: ");
	scanf("%d%f",n, c);
	int i;
	for (i=0; i<= *n; i++){
		printf("\nEnter a%d: ",i);
		scanf("%f", &A[i]);
	}
}

void calculate(float A[], int n, float c){
	float F = A[0]*1.0;
	int i;
	for (i = 1; i<=n; i++)
		F = A[i] + F*c;
	printf("\nResult = %.3f", F);
}

int main(){
	int n;
	float c, A[10];
	input(A, &n, &c);
	calculate(A,n,c);
return 0;
}

/*------------------------- END FILE ------------------------------*/