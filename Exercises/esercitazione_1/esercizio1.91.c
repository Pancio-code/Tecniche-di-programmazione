#include<stdio.h>

int main() {
	int h,i=0,l1=1;
	printf("Triangolo rettangolo data l'altezza\n");
	printf("Inserire altezza: ");
	scanf("%d", &h);
	while( i < h ) {
		int l = 0;
		while( l < l1) {
			printf("*");
			l++;
		}
		l1++;
		i++;
		printf("\n");
	}
	printf("\nIl suo simmetrico e':\n");
	i=0;
	while( i < h ) {
		int l2=1;
		while( l2 < (h-i)) {
			printf(" ");
			l2++;
		}
		int l3=0;
		while( l3 <= i ) {
			printf("*");
			l3++;
		}
		i++;
		printf("\n");
	}
}
