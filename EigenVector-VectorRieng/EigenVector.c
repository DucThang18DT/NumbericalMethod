/*-----------------------------------------------------------------*-
						EigenVector.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Description
-*-----------------------------------------------------------------*-
	calculate the eigen vectors of matrix NxN.

 * Enter:
 	N - size of matrix
	A[i][j] - value of matrix at row i and colum j
	Total number of solutions of P and its values
 * Result: 
 	Matrix P.
	eigen vectors of matrix.
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
//	}
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

void unitMatrix(float C[][10], int N){
	int i,j;
	for (i = 1; i<=N; i++)
		for (j = 1; j<=N; j++)
			if (i==j) C[i][j] = 1;
			else C[i][j] = 0;
			
//	printf("\nMa tran don vi C = \n");
//	for (i = 1; i<=N; i++){
//		for (j = 1; j<=N; j++)
//			printf("%.3f   ", C[i][j]);
//		printf("\n");
//	}
}

void assign(float C[][10], float B[][10],int N){
	int i,j;
	for (i = 1; i<=N; i++)
		for (j = 1; j<=N; j++)
			C[i][j] = B[i][j];
	
//	printf("\nGan C = B = \n");
//	for (i = 1; i<=N; i++){
//		for (j = 1; j<=N; j++)
//			printf("%.3f   ", C[i][j]);
//		printf("\n");
//	}
}

void calcY(float Y[][10], float Ng[], int N, int Num){
	int i,j;
	for (i = 1; i<= Num; i++)
		for (j = 1; j <= N; j++)
			Y[j][i] = pow(Ng[i], N-j);
			
//	printf("\ntinh Y = \n");
//	for (i = 1; i<=N; i++){
//		for (j = 1; j<=Num; j++)
//			printf("%.3f   ", Y[i][j]);
//		printf("\n");
//	}
}

void calcX(float X[][10], float Y[][10], float M[][10], int N, int Num){
	int i,j, k;
	for (i = 1; i<=N; i++)
		for (j = 1; j<=Num; j++){
			X[i][j] = 0;
			for (k = 1; k<=N; k++)
				X[i][j] += M[i][k]*Y[k][j];
		}
		
//	printf("\nTinh X = \n");
//	for (i = 1; i<=N; i++){
//		for (j = 1; j<=N; j++)
//			printf("%.3f     ", X[i][j]);
//		printf("\n");
//	}
}
void calcuate(float A[][10], int N){
	int i,j;
	float M[10][10], M1[10][10],A1[10][10], C[10][10];
	unitMatrix(C,N);
	for (i = N; i > 1 ; i--){
		matrixM1(M1, A,N,i);
		matrixM(M, A,N, i);
		multi2matrix(A1, M1,A,N);
		multi2matrix(A, A1, M,N);
		multi2matrix(A1, C, M,N);
		assign(C,A1,N);
	}
	printf("\nP = \n");
	for (i = 1; i<=N;i++){
		printf("\n");
		for (j = 1; j<=N; j++)
			printf("%.3f    ",A[i][j]);
	}
	int Num;
	float Ng[10], X[10][10], Y[10][10];
	printf("\n\nEnter number of P's solution: ");
	scanf("%d", &Num);
	for (i = 1;i<=Num; i++){
		printf("\nEnter solution number %d: ", i);
		scanf("%f",&Ng[i]);
	}
	calcY(Y,Ng,N,Num);
	calcX(X,Y,C,N,Num);
	for (i = 1; i<=Num; i++){
		printf("\nX%d = \n",i);
		for (j = 1; j<=N; j++)
			printf("%.3f  ", X[j][i]);
	}
}


int main(){
	int N,m;
	float Arr[10][10];
	input(Arr, &N);
//	printf("\nN = %d", N);
	calcuate(Arr, N);
return 0;
}


/*------------------------- END FILE ------------------------------*/