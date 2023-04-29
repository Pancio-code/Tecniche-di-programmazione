#include<stdio.h>

int main() {
	int N,successivo;
	printf("Serie di Fibonacci\n");
	printf("Inserire un numero intero:");
	scanf("%d",&N);
	if (N>=1)
		printf("\n1\n");
	if (N>=2)
		printf("1\n");
	if (N>2) {
		int i = 2;
		int precedente=1;
		int attuale=1;
		while (i<(N)) {
			successivo = attuale + precedente;
			precedente =attuale;
			attuale= successivo;
			printf("%d\n",successivo);
			i++;
			}
		}
}
			

