#include<stdio.h>

int main() {
	int a, b;
	printf("Inserire due interi finchè la somma non è 10\n");
	printf("Inserire un intero:  ");
	scanf("%d", &a);
	printf("Inserire un intero:  ");
	scanf("%d", &b);
	while( (a + b) != 10 ) {
		printf("La loro somma non e' 10\n");
		printf("\nInserire un intero:  ");
		scanf("%d", &a);
		printf("Inserire un intero:  ");
		scanf("%d", &b);
	}
	printf("FINE la somma è 10\n");
}
	
	

