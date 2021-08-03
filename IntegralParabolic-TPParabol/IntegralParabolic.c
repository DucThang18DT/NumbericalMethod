/*-----------------------------------------------------------------*-
						IntegralParabolic.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Description
-*-----------------------------------------------------------------*-
	calculate the integral from a to b of f(x) use Integral Parabolic 
	formula.

 * Enter:
 	N - max index of number sequence
	a, b - arguments
 * Result: 
 	value of the integral from a to b of f(x)
-*-----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void input(int *a, int *b, int *n){
	printf("\nEnter a,b,n: ");
	scanf("%d%d%d",a,b,n);
}

float f(float x){ // declare f(x)
	return x*1.0*x/(x-1);
}
float calc(int a, int b, int n){
	float h = (b*1.0-a)/(n*2), S = f(a)+f(b);
	int i;
	for (i = 1; i<2*n; i++)
		if (i%2==0) S += 2*f(a+i*h);
		else S += 4*f(a+i*h);
	return S*h/3;
}

int main(){
	int a,b,n;
	input(&a,&b,&n);
	printf("\n%d %d %d\n",a,b,n);
	printf("\nResult = %.3f", calc(a,b,n));
return 0;
}

/*------------------------- END FILE ------------------------------*/