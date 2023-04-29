#include<stdio.h>

int main() {
	int N,r,i=1;
	printf("Inserire lato quadrato: ");
	scanf("%d",&N);
	printf("Inserire riga dove posizionare lo snake: ");
	scanf("%d", &r);
	while (i<=N) {
		int l=0;
		if (i==1 || i==N) {
			while (l<N) {
				printf("-");
				l++;
			}
		}
		if( i == r ) {
			while (l<N) {
				if (l==0 || l==(N-2)) {
					printf("|");
				}
				if( l==2 || l==3) {
					printf("*");
				}
				else {
					printf(" ");
				}
				l++;
			}
		}
		else {
			while (l<N) {
				if (l==0 || l==(N-1)) {
					printf("|");
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
