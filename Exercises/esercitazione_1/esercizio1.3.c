#include<stdio.h>

int main() {
	int N,i=0;
	printf("Inserire lato quadrato:\n");
	scanf("%d",&N);
	while (i<N) {
		int l=0;
		while (l<N) {
			printf("*");
			l++;
		}
		printf("\n");
		i++;
	}
	
}	
