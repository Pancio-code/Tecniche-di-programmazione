#include <stdio.h>
#include <stdlib.h>

void inizializzaArrayRandom(double v[], int dim, double max_value);

void vec_print(double v[], int dim);

double* vec_sum(double v[], int dim);

double* vec_rec(double v1[], double v2[], int dim1, int dim2);

int main(int argc, char **argv) {
	int dim1 = 10;
	double max_value = 10;
	  
	printf("Inizializzo l'array con numeri random...");
	double v1[dim1];
	inizializzaArrayRandom(v1, dim1, max_value);
	printf(" done.\n\n");

	printf("v1: ");
	vec_print(v1, dim1);
	printf("\n\n");

	printf("Alloco il vettore v2...\n");
	int dim2 =5;
	double v2[dim2]={ 2.1, -3.5, 1.0, 6.5, -5.2};
	printf("La dimensione di v2 e' : %d\n",sizeof(v2));
 
	printf("Alloco il vettore v3...\n");
	int dim3=5;
	double *v3=(double *)malloc(dim3*sizeof(double));
	v3[0] = 4.8;
	v3[1] = 0.1;
	v3[2] = -6.2;
	v3[3] = -2.5;
	v3[4] = 7.2; 
  
	printf("v2: ");
	vec_print(v2, dim2);
	printf("\n");
	  
	printf("v3: ");
	vec_print(v3, dim3);
	printf("\n\n");

	printf("Calcolo il vettore somma...\n\n");
 	double *sum = vec_sum(v3, dim3);
   	vec_print(sum, dim3);
   	printf("\n");
   	free(sum);

	printf("Calcolo il vettore v3 a meno delle ricorrenze dei valori in v4...\n\n");
   	double* v4=( double *) malloc (dim3*sizeof(double));
   	v4[0]= 4.8;
   	v4[1]= 0.5;
   	v4[2]= -4.2;
   	v4[3]= -2.5;
   	v4[4]= 2.3;
   	double *v2_rec = vec_rec(v3, v4, dim2, dim3);
   	vec_print(v2_rec, dim3);
   	printf("\n");
   	free(v2_rec);

  	return 0;
}

void inizializzaArrayRandom(double v[], int dim, double max_value) {
  srand(3);
  int i;
  for (i=0;i<dim;i++){
    v[i]=rand() % 10;
  }
}

void vec_print(double v[], int dim) {
	printf("[");
	for(int i = 0; i < dim ; i++) {
		printf("%lf ",v[i]);
	}
	printf("\b]");
}

double* vec_sum(double v[], int dim) {
	double *f =(double *)malloc(sizeof(double)*dim);
	for(int i=0; i < dim;i++) {
		double somma = 0;
		for(int cont =i; cont < dim;cont++) {
			somma +=v[cont];
		}
		f[i]=somma;
	 }
	return f;
}

double* vec_rec(double v1[], double v2[], int dim1, int dim2) {
	double *p=(double *)malloc(sizeof(double)*dim1);
	for(int k = 0; k < dim1; k++) {
		for(int i = 0; i < dim2; i++) {
			if( v1[k] != v2[k] ) 
				p[k] = 0.0;
			else {
				p[k] =v1[k];
				break;
			}
		}
	}
	return p;
}




			
	
		

