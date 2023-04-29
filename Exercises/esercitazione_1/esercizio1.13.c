#include<stdio.h>
#include<math.h>
#define SOGLIA 0.000001

int main() {
	float x,rn,rn_1,diff,r;
	printf("Calcolo della radice quadrata di un numero con il metodo di Newton\n\n");
	printf("Inserire il numero x di cui calcolare la radice:\n");
	scanf("%f", &x );
	rn_1=x;
	diff=2*SOGLIA;
	while( diff > SOGLIA ) {
		rn=(rn_1+(x/rn_1))/2;
		diff=fabs(rn-rn_1);
		rn_1=rn;
	}
	r=sqrt(x);
	printf("\nLa radice di x equivale a: %f\n\nInvece con sqrt è: %f\n",rn,r);
}
	
