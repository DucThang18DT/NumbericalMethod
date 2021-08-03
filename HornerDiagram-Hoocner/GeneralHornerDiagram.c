/*-----------------------------------------------------------------*-
						GeneralHornerDiagram.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Description
-*-----------------------------------------------------------------*-
	calculate the value of the function use general Horner diagram.

 * Enter:
 	N - highest degree of the equation
	ai - coefficients of the equation
	c - value at which to calculate the function value 
 * Result: 
 	value of funtion at y+c.
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
	int i,j;
	for (i = n; i>=1; i--){
		printf("%.3f\t",A[0]);
		for (j = 1; j <=i; j++){
			A[j] += A[j-1]*c;
			printf("%.3f\t",A[j]);
		}
		printf("\n");
	}
}

int main(){
	int n;
	float c, A[10];
	input(A, &n, &c);
	calculate(A,n,c);
return 0;
}


/*------------------------- END FILE ------------------------------*/
