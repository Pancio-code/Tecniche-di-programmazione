#include<stdio.h>
#include<math.h>

int main() {
	printf("Convertitore binario-decimale\n");
	int i=0;
	int N,valore = 0,b;
	printf("Inserire numero di bit: ");
	scanf("%d", &N);
	int potenza=N-1;
	while( i < N ) {
		printf("Inserire 0 o 1 (dal bit di peso 1):\n");
		scanf("%d", &b);
		int c = pow(2.0,potenza);
		valore= valore + (b*c);
		potenza=potenza - 1;
		i++;
	}
	printf("IL numero decimale è uguale a %d\n",valore);
}

			
