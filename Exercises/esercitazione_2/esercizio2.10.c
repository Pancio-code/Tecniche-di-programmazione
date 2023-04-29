#include<stdio.h>
#include<stdlib.h>
#define KELVIN 273.15

int main(void) {
	float *t=(float *)malloc(sizeof(float));
	char *s=(char *)malloc(sizeof(char));
	printf("C = Celsius , F = Fahrenheit ,K= kelvin\n\n");
	printf("Inserire temperatura:\n");
	scanf("%f",t);
	printf("Inserire scala di temperatura:\n");
	scanf(" %c",s);
	if(*s == 'C' || *s == 'c') {
		printf("La temperatura in Kelvin e' %f K\n",*t + KELVIN);
		printf("La temperatura in Fahrenheit e' %f F\n", *t * (9.0/5.0) + 32);
	}
	else if(*s == 'K' || *s == 'k') {
		printf("La temperatura in Celsius e' %f °C\n",*t - KELVIN);
		printf("La temperatura in Fahrenheit e' %f F\n", (*t - KELVIN) * (9.0/5.0) + 32);
	}
	else if(*s == 'F' || *s == 'f') {
		printf("La temperatura in Celsius e' %f °C\n",(*t - 32)*(5.0/9.0));
		printf("La temperatura in Kelvin e' %f K\n",((*t - 32)*(5.0/9.0)) + KELVIN ) ;
	}
	else {
		printf("Unità di misura errata\n");
	}
	free(t);
	free(s);
	t=NULL;
	s=NULL;
}
	
		
	
