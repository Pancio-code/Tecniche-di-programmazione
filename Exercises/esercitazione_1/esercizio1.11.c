#include<stdio.h>

int main() {
	int N,i=0,c=1;
	printf("Triangolo di Floyd\n");
	printf("Inserire intero N>0: ");
	scanf("%d", &N);
	while( i < N ) {
		int l=0;
		while( l <= i ) {
			printf("%d ",c);
			l++;
			c++;
		}
		printf("\n");
		i++;
	}
}
