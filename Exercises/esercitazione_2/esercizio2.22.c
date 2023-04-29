#include<stdio.h>
#include<math.h>

int main() {
	unsigned char b;
	short s;
	int i;
	long l;
	float f;
	double d;
	char c;

	printf("inserire un valore u-char: ");
	scanf("%c", &b);
	printf("inserire un valore short: ");
	scanf("%hd", &s);
	printf("inserire un valore int: ");
	scanf("%d", &i);
	printf("inserire un valore long: ");
	scanf("%ld", &l);
	printf("inserire un valore float: ");
	scanf("%f", &f);
	printf("inserire un valore double: ");
	scanf("%lf", &d);
	printf("inserire un valore char: ");
	scanf(" %c", &c);
	
	printf("\nIl risultato di %u + 10l = %d\n",b,(int)( b + 10l));
	printf("Il risultato di (%u + %d)*%ld = %d\n",b,i,l,(int)((b+i)*l));
	printf("Il risultato di (%u + %d)*%ld+%f = %d\n",b,i,l,f, (int)((b+i)*l+f));
	printf("Il risultato di %hd/%f + sin(%f) = %d\n",s,f,f,(int)( s/f + sin(f)));
	printf("Il risultato di %c == 'b' e' %d\n",c,(int)( c == 'b'));
	printf("Il risultato di %ld + 1.5f = %d\n",l, (int)(l + 1.5f));
	printf("Il risultato di %d < 10 e' %d\n",i, (int)(i < 10));
}
	
