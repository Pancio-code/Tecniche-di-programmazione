#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KELVIN 273.15f

int* allocaInt();

void inizializzaInt(int* i1, int* i2, int matricola);

void printInt(int *i1, int *i2);

int MCD(int i1, int i2);

int mcm(int i1, int i2);

void conversioneTemperatura(int t, char c);

void* conversioneTemperatura(int* t, char c);

void printConversione(void* temperatura);

void soluzioneSistemaLineare(int i1, int i2);

void differenzaPuntatori(int *i1, int *i2);

void fibonacci(int N);



int main(int argc, char **argv) {
  int *i1 = allocaInt();
  int *i2 = allocaInt();
  printf("\n");

  printf("Inizializzo i due interi con numeri random...");
  inizializzaInt(i1, i2, 1884749);
  printf(" done.\n\n");

  printf("i1, i2: ");
  printInt(i1, i2);
  printf("\n\n");

  printf("calcolo il MCD...\n");
  int mcd = MCD(*i1, *i2);
  printf("il MCD è %d\n\n", mcd);

  printf("calcolo il mcm...\n");
  int res = mcm(*i1, *i2);
  printf("il mcm è %d\n\n", res);

  printf("test conversioneTemperatura...\n");
  conversioneTemperatura(*i1, 'C');
  void* temperatura = conversioneTemperatura(i1, 'C');
  printf("\n");
  printConversione(temperatura);
  free(temperatura);
  printf("\n");


  printf("Calcolo la soluzione del sistema lineare i1 x + i2 = 0...");
  soluzioneSistemaLineare(*i1, *i2);
  printf("\n");


  printf("Cambio del valore puntato da i2...\n");
  differenzaPuntatori(i1, i2);
  printf("i2 : %d\n\n", *i2);


  printf("Calcolo dei primi %d numeri della serie di Fibonacci ...", *i1);
  fibonacci(*i1);
  printf("\n");  

  free(i1);
  free(i2);
	
  printf("Altri esercizi...");
  int a,b,n1;
  printf("Inserire un intero a: ");
  scanf("%d", &a);
  printf("Inserire un intero b: ");
  scanf("%d", &b);
  printf("il mcm e' %d\n",mcm(a,b));
  printf("il MCD e' %d\n",MCD(a,b));
  printf("Inserire un intero n1 per la serie di fibonacci: ");
  scanf("%d", &n1);
  fibonacci(n1);
  return 0;
}

int* allocaInt(){
	int *r=(int *)malloc(sizeof(int));
	return r;
}

void inizializzaInt(int* i1, int* i2, int matricola){
  srand(matricola); // decommentare per avere sempre gli stessi due numeri (utile per debug)
  srand(time(0)); // decommentare per avere numeri diversi ad ogni esecuzione
  *i1=rand() % 20;
  *i2=rand() % 20;

  while(*i1 ==0)
	*i1=rand() % 20;

  while(*i2 ==0)
	*i2=rand() % 20;
}

void printInt(int *i1, int *i2){
	printf("%d , %d\n",*i1,*i2);
	return;
}

int MCD(int i1, int i2){
	int k,mcd;
	if(i1 >= i2){
		k=i2;
	}
	else{
		k=i1;
	}
	for(k;k>0;k--) {
		if( i2%k==0 && i1%k==0){
			mcd=k;
			break;
		}
	}
	return mcd;
}

int mcm(int i1, int i2){
  	int M,mcm,i=1;
	if( i1 >= i2 ) {
		M=i1;
		mcm=i1;
	}
	else {
		M=i2;
		mcm=i2;
	}
	while( mcm%i1!=0 || mcm%i2!=0 ) {
		mcm = M*i;
		i++;
	}
	return mcm;
}

void conversioneTemperatura(int t, char c){
	if(c == 'C' || c == 'c') {
		printf("La temperatura in Kelvin e' %f K\n",t + KELVIN);
		printf("La temperatura in Fahrenheit e' %f F\n", t * (9.0/5.0) + 32);
	}
	else if(c == 'K' || c== 'k') {
		printf("La temperatura in Celsius e' %f °C\n",t - KELVIN);
		printf("La temperatura in Fahrenheit e' %f F\n", (t - KELVIN) * (9.0/5.0) + 32);
	}
	else if(c == 'F' || c == 'f') {
		printf("La temperatura in Celsius e' %f °C\n",(t - 32)*(5.0/9.0));
		printf("La temperatura in Kelvin e' %f K\n",((t - 32)*(5.0/9.0)) + KELVIN ) ;
	}
	return;
}

void* conversioneTemperatura(int* t, char c){
	void *m=malloc(sizeof(int)+sizeof(char)+sizeof(int)+sizeof(char));
	float* temp = (float *)m;
	float* temp1 = (float *)m + 1*sizeof(float);
	char* scala = (char *)((float *)m + 2*sizeof(float));
	char* scala1 = (char *)((float *)m + 2*sizeof(float)) + 1*sizeof(char);
  	if(c == 'C' || c == 'c') {
			*temp=*t + KELVIN;
			*scala='K';
			*temp1=*t * (9.0/5.0) + 32;
			*scala1='F';
	}
	else if(c == 'K' || c== 'k') {
			*temp=*t - KELVIN;
			*scala='C';
			*temp1=(*t - KELVIN) * (9.0/5.0) + 32;
			*scala1='F';
	}
	else if(c == 'F' || c == 'f') {
			*temp=(*t - 32)*(5.0/9.0);
			*scala='C';
			*temp1=(*t - 32)*(5.0/9.0) + KELVIN  ;
			*scala1='K';
	}
	return m;
}

void printConversione(void* temperatura){
	float* temp = (float *)temperatura;
	float* temp1 = (float *)temperatura + 1*sizeof(float);
	char* scala = (char *)((float *)temperatura + 2*sizeof(float));
	char* scala1 = (char *)((float *)temperatura + 2*sizeof(float)) + 1*sizeof(char);
	if(*scala== 'C' || *scala == 'c') {
		printf("La temperatura in Celsius e' %f °C\n",*temp);
	}
	else if(*scala == 'K' || *scala == 'k') {
		printf("La temperatura in Kelvin e' %f K\n",*temp);
	}
	else if(*scala == 'F' || *scala == 'f') {
		printf("La temperatura in Fahrenheit e' %f F\n",*temp);
	}
	if(*scala1== 'C' || *scala1 == 'c') {
		printf("La temperatura in Celsius e' %f °C\n",*temp1);
	}
	else if(*scala1 == 'K' || *scala1 == 'k') {
		printf("La temperatura in Kelvin e' %f K\n",*temp1);
	}
	else if(*scala1 == 'F' || *scala1 == 'f') {
		printf("La temperatura in Fahrenheit e' %f F\n",*temp1);
	}
	return;
}

void soluzioneSistemaLineare(int i1, int i2){
	float x;
	if( i1 != 0) {
		if( i2 != 0) {
			x= - (float)i2 / (float)i1  ;
			printf("\nLa soluzione e' x =  %f\n", x);
		}
		else {
			x= 0;
			printf("\nLa soluzione e' x =  %f\n", x);
		}
	}
	else {
		if( i2==0 ) {
			printf("\nIL sistema ammette infinite soluzioni\n");
		}
		else {
			printf("\nIl sistema è impossibile (non ammette soluzioni)\n");
		}
	}
	return;
}

void differenzaPuntatori(int *i1, int *i2){
	int distanza = i2 - i1;
	*i2= *i1 + distanza;
	printf("%d\n",distanza);
	return;
}

void fibonacci(int N){
	if(N < 1) {
		printf("Il limite della serie deve essere un-intero strettamente positivo!\n");
	}
	if(N >= 1) {
    		printf("\n1");
  	}
  	if(N >= 2) {
    		printf(", 1");
  	}
	if(N > 2) {
  		long int f_i_1 = 1, f_i_2 = 1;
  		for(int i = 3; i <= N; ++i) {
    			long int f_i = f_i_2 + f_i_1;
    			printf(", %ld", f_i);
    			f_i_2 = f_i_1;
    			f_i_1 = f_i;
  		}
	}
  	printf("\n");
}
