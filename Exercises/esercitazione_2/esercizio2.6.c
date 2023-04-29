#include<stdio.h>

int main() {
	int i = 10, j = -1;
	char *p, *q;
	p = (char *)&i;
	q = (char *)&j;
	for(int k = 0;k < 4;k++) {
		*(q+k) = *(p+k);
	}
	printf("%08x == %08x\n", i, j);
	printf("%d == %d\n", i, j);
}
