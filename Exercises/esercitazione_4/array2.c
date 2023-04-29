#include <stdio.h>
#include <stdlib.h>

void inizializzaArrayRandom(double v[], int dim, double max_value);

void vec_print(double v[], int dim);

void vec_scale(double v[], int dim, double scale);

double vec_dot(double src1[], double src2[], int dim);

double* vec_clone(double v[], int dim);

bool vec_positive_check(double v[], int dim);

int main(int argc, char **argv) {
  int dim1 = 10;
  double max_value = 10;
  
  /********************************************************
   *              TEST inizializzaArrayRandom             *
   ********************************************************/
  printf("Inizializzo l'array con numeri random...");
  double v1[dim1];
  inizializzaArrayRandom(v1, dim1, max_value);
  printf(" done.\n\n");

  printf("v1: ");
  vec_print(v1, dim1);
  printf("\n\n");
  
  printf("Alloco il vettore v3...\n");
  int dim3=5;
  double *v3=(double *)malloc(dim3*sizeof(double));
  v3[0] = 9.8;
  v3[1] = 6.1;
  v3[2] = -3.2;
  v3[3] = -1.5;
  v3[4] = .2;
  printf("v3: ");
  vec_print(v3, dim3);
  printf("\n\n");
  
  printf("Alloco il vettore v2...\n");
  int dim2 =5;
  double v2[dim2]={ 5.3, -4.5, 2.0, 10.5, -8.2};
  printf("v2: ");
  vec_print(v2, dim2);
  printf("\n\n");


  /********************************************************
   *                    TEST vec_scale  v3                *
   ********************************************************/
   printf("Scalo v3 di un fattore di 0.5...");
   vec_scale(v3, dim3, 0.5);
   printf(" done.\n");
   printf("v3: ");
   vec_print(v3, dim3);  
   printf("\n\n");

  /********************************************************
   *                    TEST vec_dot  v2°v3
   *
   ********************************************************/
  printf("Calcolo il prodotto scalare tra v2 e v3...");
  double dot = vec_dot(v2, v3, dim2);
  printf(" done.\n");
  printf("Il prodotto scalare tra v2 e v3 e': %lf\n\n", dot);

  /********************************************************
   *                    TEST vec_clone  v2                *
   ********************************************************/
  printf("Clono v2...");
  double *copy_v2 = vec_clone(v2, dim2);
  printf(" done.\n");
  printf("Copia v2: ");
  vec_print(copy_v2, dim2);
  printf("\n\n");  

  /********************************************************
  *                    TEST vec_positive_check  v2        *
  ********************************************************/
  printf("Controllo che tutti i numeri di v2 siano positivi...\n");
  printf( "%s\n", vec_positive_check( v2, dim2)? "true: tutti i numeri sono positivi" : "false: almeno un numero è negativo" );

  free(copy_v2);
  free(v3);

  return 0;
}

void inizializzaArrayRandom(double v[], int dim, double max_value) {
  srand(3);
  for (int i=0;i<dim;i++){
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

void vec_scale(double v[], int dim, double scale) {
	for(int i = 0; i < dim; i++) {
		v[i]=v[i]*scale;
	}
	return;
}	

double vec_dot(double src1[], double src2[], int dim) {
	double ris=0.0;
	for(int i=0; i < dim; i++) {
		ris+=src1[i]*src2[i];
	}
	return ris;
}

double* vec_clone(double v[], int dim) {
	double *m=(double *)malloc(dim*sizeof(double));
	for(int i = 0; i < dim;i++) {
		m[i]=v[i];
	}
	return m;
}

bool vec_positive_check(double v[], int dim) {
	for(int i=0 ;i < dim; i++) {
		if( v[i] < 0.0 ) {
			return false;
		}
	}
	return true;
}
