/*-----------------------------------------------------------------*-
						ResidualElimination.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Descreption
-*-----------------------------------------------------------------*-
	solve the system of equations and print the result use 
	Residual Elimination method.

 * Enter:
 	N - size of matrix
	A[i][j] - value of matrix at row i and colum j
 * Result: 
 	Solutions of system of equations.
-*-----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

int N;
float Arr[10][10];

void input(){	
	printf("Enter n: ");
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++)
		for (j = 1; j<= N+1; j++){
			printf("\nEnter A[%d][%d]: ", i,j);
			scanf("%f", &Arr[i][j]);
		}
}

int isConverging(float A[3][N+1]){
	int i;
	for (i = 1; i<=N; i++)
		if (abs(A[2][i]*10000) >= 1) 
			return 0;
	return 1;
}

int Max(float A[3][N+1]){
	int max = 1,i;
	for (i = 2; i<=N; i++)
		if (abs(A[2][i]*10000) >= abs(A[2][max]*10000))
			max = i;
	return max;
}

void calculate(){
	float Ng[3][N+1];
	int i,j;
	
	// divide each row by A[i][i]		
	for (i = 1; i <=N; i++){
		for (j = 1; j<=N+1; j++)
			if (i != j) Arr[i][j] /= Arr[i][i];
		Arr[i][i] = 1;
	}
	
	// solution init
	for (i = 1; i<= N; i++) 
		Ng[1][i] = 0;
		
	for (i = 1; i <= N ; i++){
		Ng[2][i] = Arr[i][N+1];
		for (j = 1; j <= N; j++)
			if (i != j) Ng[2][i] -= Arr[i][j]*Ng[1][j];
	}
		
	while (1){
		i = Max(Ng);
		for (j = 1; j<=N; j++){
			if (j==i) Ng[1][i] += Ng[2][i];
			else Ng[2][j] -= Arr[j][i]*Ng[2][i];
		}
		Ng[2][i] = 0;
		if (isConverging(Ng)) break;
	}
	
	for (i = 1; i <= N; i++)
		printf("\nX%d = %f",i,Ng[1][i]);

}

int main(){
	input();
	calculate();
return 0;
}

/*------------------------- END FILE ------------------------------*/