#include<stdio.h>

int main() {
	 int h,t;
	 printf("inserire altezza totale dell'albero: ");
	 scanf("%d", &h);
	 printf("inserire altezza del tronco: ");
	 scanf("%d", &t);
	 int i= 1;
	 while (i<=h) {
		if( i <= (h-t)) {
			int c=0;
			while (c<(h-i)) {
				printf(" ");
				c++;
			 }
			int c1=0;
			while (c1<(2*i-1)) {
				printf("*");
				c1++;
			}
		}
		else {
			int c=0;
			while (c < (h-1) ) {
				printf(" ");
				c++;
			 }
			printf("*");
		}
		printf("\n");
		i++;	
	 }
}
