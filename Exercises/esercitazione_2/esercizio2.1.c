#include<stdio.h>

int main() {
	int a = 121021;
	char b = 'F';
	short int c = 12000;
	long int d = 2922991090290102;
	float e = 1.213131;
	double f = 1.1233242525;
	printf("L'indirizzo di a e' %p, occopa %d bytes, il suo valore è %d\n",&a, sizeof(a), a);
	printf("L'indirizzo di b e' %p, occopa %d bytes, il suo valore è %c\n",&b, sizeof(b), b);
	printf("L'indirizzo di c e' %p, occopa %d bytes, il suo valore è %hd\n",&c, sizeof(c), c);
	printf("L'indirizzo di d e' %p, occopa %d bytes, il suo valore è %ld\n",&d, sizeof(d), d);
	printf("L'indirizzo di e e' %p, occopa %d bytes, il suo valore è %f\n",&e, sizeof(e), e);
	printf("L'indirizzo di f e' %p, occopa %d bytes, il suo valore è %lf\n",&f, sizeof(f), f);
}
