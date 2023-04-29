#include<stdio.h>

int main() {
	int a,b,c;
	printf("Inserie un intero:");
	scanf("%d", &a);
	printf("Inserie un intero:");
	scanf("%d", &b);
	printf("Inserie un intero:");
	scanf("%d", &c);
	if( a < b ) {
		if( c <=  a ) {
			printf("In ordine decrescente: %d %d %d\n",b,a,c);
		}
		else if( c >= b ) {
			printf("In ordine decrescente: %d %d %d\n",c,b,a);
		}
		else if( c > a && c < b ) {
			printf("In ordine decrescente: %d %d %d\n",b,c,a);
		}				
	}		
	if( b < a ) {
		if( c <=  b ) {
			printf("In ordine decrescente: %d %d %d\n",a,b,c);
		}
		else if( c >= a ) {
			printf("In ordine decrescente: %d %d %d\n",c,a,b);
		}
		else if( c > b && c < a ) {
			printf("In ordine decrescente: %d %d %d\n",a,c,b);
		}	
	}
	if( b == a ) {
		if( c <=  a ) {
			printf("In ordine decrescente: %d %d %d\n",b,a,c);
		}
		else if( c >= b) {
			printf("In ordine decrescente: %d %d %d\n",c,b,a);
		}
		else if( c == a ) {
			printf("In ordine decrescente: %d %d %d\n",b,c,a);
		}		
	}
}
