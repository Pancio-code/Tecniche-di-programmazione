#include<stdio.h>

int main() {
	int M,a,b,mcm,i=1;
	printf("Minimo comune multiplo\n");
	printf("Inserire un intero N1: ");
	scanf("%d", &a);
	printf("Inserire un intero N2: ");
	scanf("%d", &b);
	if( a >= b ) {
		M=a;
		mcm=a;
	}
	else {
		M=b;
		mcm=b;
	}
	while( mcm%a!=0 || mcm%b!=0 ) {
		mcm = M*i;
		i++;
	}
	printf("il m.c.m. è = %d\n",mcm);
}
