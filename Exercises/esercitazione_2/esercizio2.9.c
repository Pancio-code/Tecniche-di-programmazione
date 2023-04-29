#include<stdio.h>

int main() {
  	int a = 0, b = 0;  
  	printf("a = %d\n", a);
  	printf("b = %d\n", b);
  	printf("&a = %p\n", &a);
  	printf("&b = %p\n", &b);
  	int dptr = &a - &b;
  	printf("dptr = %d\n", dptr);
  	
  	*(&b + dptr) = 1;
  	printf("a = %d\n", a);
  	printf("b = %d\n", b);
  
  	return 0;
}
