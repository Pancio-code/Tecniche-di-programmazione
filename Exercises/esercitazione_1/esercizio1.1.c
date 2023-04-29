#include<stdio.h>

int main() {
	float a,b,x;
	printf("Risoluzione equazioni di primo grado\n");
	printf("Equazione nella forma: ax + b = 0\n");
	printf("Immetti coefficente a: ");
	scanf("%f", &a);
	printf("Imetti coefficente b: ");
	scanf("%f", &b);
	
	if( a != 0) {
		if( b != 0) {
			x= - b / a  ;
			printf("La soluzione e' x =  %f\n", x);
		}
		else {
			x= 0;
			printf("La soluzione e' x =  %f\n", x);
		}
	}
	else {
		if( b==0 ) {
			printf("Equazione indeterminata (ammette infinite soluzioni)\n");
		}
		else {
			printf("Equazione impossibile (non ammette soluzioni)\n");
		}
	}
}


