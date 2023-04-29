#include<stdio.h>

int main() {
	int a = 1;
	printf("Inserire un intero( 0 per terminare):\n");
	scanf("%d", &a);
	while( a != 0 ) {
		printf("\n");
		int i = 0;
		while( i < a ) {
			printf("*");
			i++;
		}
		printf("\n\n");
		scanf("%d", &a);
	}
}
		
