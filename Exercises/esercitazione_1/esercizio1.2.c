#include<stdio.h>

int main() {
	float a,media = 0;
	printf("Calcolatore media aritmetica\n");
	printf("Inserire un valore( 0 per terminare):\n");
	scanf("%f" , &a );
	if( a != 0 ) {
		int i = 1;
		while( a != 0 ) {
			media += a;
			scanf("%f" , &a );
			if( a != 0 )
				i++;
			}
		media = media/i;
		printf("La media aritmetica e' = %f\n",media);
		}
	else
		printf("Non ci sono valori per calcolare la media!\n");
	}

			 
