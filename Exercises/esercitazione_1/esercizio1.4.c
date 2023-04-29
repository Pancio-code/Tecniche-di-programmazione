#include<stdio.h>

int main() {
	int N,i=0;
	printf("Inserire lato quadrato:\n");
	scanf("%d",&N);
	while (i<N) {
		int l=0;
		if (i==0 || i==(N-1)) {
			while (l<N) {
				printf("*");
				l++;
			}
		}
		else {
			while (l<N) {
				if (l==0 || l==(N-1)) {
					printf("*");
				}
				else {
					printf(" ");
				}
				l++;
			}
		}
		printf("\n");
		i++;
	}
	
}
