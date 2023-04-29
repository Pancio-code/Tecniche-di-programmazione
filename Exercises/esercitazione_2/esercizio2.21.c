#include<stdio.h>

int main() {
	float a =260.1;
	printf("%f\n",a);
	int d = (int)a;
	printf("%04X\n",d);
	unsigned char c = (unsigned char) d;
	printf("%04X\n",c);
}
