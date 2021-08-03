/*-----------------------------------------------------------------*-
						HornerDiagram.c
-*-----------------------------------------------------------------*-
	Create   					: 	15/05/2021
	Latest Modified 			: 	03/08/2021
	By      					: 	Pham Duc Thang
	Language 					: 	C
-*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*-
						Descreption
-*-----------------------------------------------------------------*-
	calculate the integral from a to b of f(x) use Newton - Cotes 
	formula.

 * Enter:
	a, b - arguments
 * Result: 
 	value of the integral from a to b of f(x)
-*-----------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void input(int *a, int *b){
	printf("\nNhap a,b: ");
	scanf("%d%d",a,b);
}

float f(float x){ // declare f(x)
	return x*1.0*x/(x-1);
}
float calc(int a, int b){
	float h = (b*1.0-a)/6, S = 0; 
	float P[] = {41.0/840, 9.0/35, 9.0/280, 34.0/105, 9.0/280, 9.0/35, 41.0/840};
	int i;
	for (i = 0; i<=6; i++)
		S += f(a+i*h)*P[i];
	return (b-a)*S;
}
int main(){
	int a,b;
	input(&a,&b);
	printf("\nResult = %.3f", calc(a,b));
return 0;
}

/*------------------------- END FILE ------------------------------*/