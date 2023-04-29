#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
	printf("generare codice di a casualmente\n\n");
	srand(time(NULL));
	int r = rand(),i=1;
	while( r != 96 ) {
		r = rand();
		i++;
	}
	printf("il valore di a è = %d\n",r);
	printf("per generare il codice della lettera a ci sono volute %d iterazioni\n",i);
}	
	
