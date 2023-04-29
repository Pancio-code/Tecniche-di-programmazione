#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() {
	int *q;
	printf("%d\n",sizeof(q));
	if(sizeof(q)<=4)
		printf("unsigned int\n");
	else if((sizeof(q))>4 && sizeof(q)<=32)
		printf("unsigned long int\n");
	else if((sizeof(q))>32 && sizeof(q)<=64)
		printf("unsigned long long int\n");


	return 0;
}
