#include<stdio.h>

int main() {
	int N,M,i=0;
	printf("Scacchiera N*MxM*N\n");
	printf("Inserire N:");
	scanf("%d",&N);
	printf("Inserire M:");
	scanf("%d",&M);
	if(N%M==0) {
		int l2=0;
		while(i<(M*N)) {
			int l=0, l1=0;
			if( l2 < M ) {
				while(l<M*N) {
					if( l1 < M ) {
						printf("*");
						l++;
						l1++;
					}
					else if( l1 >= M && l1 < (2*M)) {
						printf("-");
						l1++;
						l++;
					}
					else if( l1 == (2*M)) {
						l1=0;
					}
				}
				l2++;
			}
			else if( l2 >= M && l2 < (2*M)) {
				while(l<M*N) {
					if( l1 < M ) {
						printf("-");
						l++;
						l1++;
					}
					else if( l1 >= M && l1 < (2*M)) {
						printf("*");
						l1++;
						l++;
					}
					else if( l1 == (2*M)) {
						l1=0;
					}
				}
				l2++;
				if( l2 == (2*M)) {
					l2=0;
				}
			}
			printf("\n");
			i++;
		}
	}
	else {
		printf("M non è un sottomultiplo di N\n");
	}
}
