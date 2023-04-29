#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int *p=(int *)malloc(2*sizeof(int));
	int *m=p+1;	
	printf("Inserire un intero positivo( 0 per terminare):\n");
	scanf("%d",p);
	*m=*p;
	if(*p < 0) {
		free(p);
		p=NULL;
		printf("Errore inserito intero negativo\n");
	}
	else {
		while( *p != 0 ) {
			if( *p <= *m) {
				*m=*p;
			}
			scanf("%d",p);
		}
		if(*m < 0) {
			printf("Errore inserito intero negativo\n");
		}
		else {
			printf("minimo = %d\n",*m);
		}
		free(p);
		p=NULL;
	} 
  }
