/*-----------------------------------------------------------------*-
					DiferenceEquationsTable.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Description
-*-----------------------------------------------------------------*-
	calculate the value and print out the Diference Equations Table

 * Enter:
 	N - max index of number sequence
	xi - value of x at index i
	yi - value of y at index i
 * Result: 
 	Diference Equations Table
-*-----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void input(float Fx[][20], int *N){
	printf("Enter N: ");
	scanf("%d", N);
	int i,j;
	for (i = 0; i <= *N; i++){
		printf("Enter x[%d]: ", i);
		scanf("%f", &Fx[i][0]);
	}
	for (i = 0; i <= *N; i++){
		printf("Enter y[%d]: ", i);
		scanf("%f", &Fx[i][1]);
	}
}

void calculate(float Fx[][20], int N){
	int i,j;
	for (i = 2; i<=N+1; i++)
		for (j = N; j>=i-1; j--)
			Fx[j][i] = Fx[j][i-1] - Fx[j-1][i-1];
			
	for (i = 0; i <= N; i++ ){
		for (j = 0; j<=i+1; j++)
			printf("%.2f\t", Fx[i][j]);
		printf("\n");
	}
}

int main(){
	int N;
	float Fx[20][20];
	input(Fx, &N);
	calculate(Fx, N);
return 0;
}


/*------------------------- END FILE ------------------------------*/