#include<stdio.h>

int main() {
	int a,min;
	printf("Valore Minimo\n");
	printf("Inserire un intero( 0 per terminare ):\n");
	scanf("%d", &a);
	min = a;
	if (a!=0) {	
		while (a!=0) {
			if (a <= min) {
				min =a;
			}
			scanf("%d", &a);
		}
		printf("\nIl valore minimo è: %d\n",min);
	}
	else
		printf("Hai inserito 0\n");
}
		
		
		
