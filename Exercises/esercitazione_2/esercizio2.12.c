#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int N;
	printf("Inserire un intero N:\n");
	scanf("%d",&N);
	int *m=(int *)malloc(N*sizeof(int));
	for(int k=0;k<N;k++) {
		printf("indirizzo = %p ; contenuto = %d\n",(m+k),*(m+k));
	}
	free(m);
	m=NULL;
}
			
