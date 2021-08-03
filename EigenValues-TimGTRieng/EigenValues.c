/*-----------------------------------------------------------------*-
						EigenValues.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Description
-*-----------------------------------------------------------------*-
	calculate the Eigen Values of matrix NxN.

 * Enter:
 	N - size of matrix
	A[i][j] - value of matrix at row i and colum j
 * Result: 
 	Matrix P.
-*-----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void matrixM1(float M1[][10], float A[][10], int N, int m){
	int i,j;
	for (i = 1; i<=N; i++)
		for (j = 1; j<=N; j++){
			//if (i==m-1) break;
			if (i==j) M1[i][j] = 1;
			else M1[i][j] = 0;
		}
	for (i = 1; i<= N; i++)
		M1[m-1][i] = A[m][i];
		
//	printf("\nM1 = \n");
//	for (i = 1; i<=N; i++){
//		for (j = 1; j<=N; j++)
//			printf("%.3f   ", M1[i][j]);
//		printf("\n");
	// }
}

float matrixM(float M[][10], float A[][10], int N, int m){
	int i,j;
	for (i = 1; i<=N; i++)
		for (j = 1; j<=N; j++){
			//if (i==m-1) break;
			if (i==j) M[i][j] = 1;
			else M[i][j] = 0;
		}
	for (i = 1; i<= N; i++)
		if (i == m-1) M[m-1][i] = 1/A[m][m-1];
		else M[m-1][i] = -A[m][i]/A[m][m-1];
		
//	printf("\nM = \n");
//	for (i = 1; i<=N; i++){
//		for (j = 1; j<=N; j++)
//			printf("%.3f   ", M[i][j]);
//		printf("\n");
//	}
}

void multi2matrix(float C[][10], float A[][10], float B[][10], int N){
	int i,j, k;
	for (i = 1; i<=N; i++)
		for (j = 1; j<=N; j++){
			C[i][j] = 0;
			for (k = 1; k<=N; k++)
				C[i][j] += A[i][k]*B[k][j];
		}
		
//	printf("\nC = \n");
//	for (i = 1; i<=N; i++){
//		for (j = 1; j<=N; j++)
//			printf("%.3f   ", C[i][j]);
//		printf("\n");
//	}
}

void input(float A[10][10],int *N){
	printf("Enter N: ");
	scanf("%d", N);
	int i, j;
	for (i = 1;i<= *N;i++)
		for(j= 1;j <= *N; j++){
			printf("Enter A[%d][%d]: ",i,j);
			scanf("%f", &A[i][j]);
		}
}

void calculate(float A[][10], int N){
	int i,j;
	float M[10][10], M1[10][10],A1[10][10];
	for (i = N; i > 1 ; i--){
		matrixM1(M1, A,N,i);
		matrixM(M, A,N, i);
		multi2matrix(A1, M1,A,N);
		multi2matrix(A, A1, M,N);
	}
	printf("\nP = \n");
	for (i = 1; i<=N;i++){
		printf("\n");
		for (j = 1; j<=N; j++)
			printf("%.3f    ",A[i][j]);
	}
}

int main(){
	int N;
	float Arr[10][10];
	input(Arr, &N);
//	printf("\nN = %d", N);
	calculate(Arr, N);
return 0;
}


/*------------------------- END FILE ------------------------------*/