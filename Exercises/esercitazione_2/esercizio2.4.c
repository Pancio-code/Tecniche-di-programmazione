#include<stdio.h>
#include<math.h>
#include <limits.h>
#define BYTE_BIT 8

int main() {
	int a=sizeof(int),b;
	int c;
	b=a*BYTE_BIT;
	c=pow(2,(b-1))-1;
	printf("Il più grande numero rappresentabile con %d byte e' %d\n",a,c);
	printf("La soluzione e' = %d\n", INT_MAX);
	return 0;
}
