#include "es5_mat.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	Mat* m1= Mat_read("mat.txt");
	Mat* m2= Mat_read("mat_1.txt");
	Mat* m3= Mat_read("mat_2.txt");
	Mat* m4= Mat_read("mat_3.txt");
	Mat* m5= Mat_read("mat_4.txt");

	printf("La matrice m1 e': \n\n");
	Mat_print(Mat_clone(m1));
	printf("La matrice m2 e': \n\n");
	Mat_print(Mat_clone(m2));
	printf("La matrice m3 e': \n\n");
	Mat_print(Mat_clone(m3));
	printf("La matrice m4 e': \n\n");
	Mat_print(Mat_clone(m4));
	printf("La matrice m5 e': \n\n");
	Mat_print(Mat_clone(m5));
	
	printf("La matrice m3 normalizzata e': \n\n");
	Mat* m6=Mat_clone(m3);
	Mat_normalize_rows(m6);
	Mat_print(m6);
	Mat_free(m6);

	printf( "%s\n", Mat_is_symmetric(m1) ? "true: La matrice m1 e' simmetrica" : "false: La matrice m1 non e' simmetrica" );
	printf( "%s\n", Mat_is_symmetric(m2) ? "true: La matrice m2 e' simmetrica" : "false: La matrice m2 non e' simmetrica" );
	printf( "%s\n", Mat_is_symmetric(m3) ? "true: La matrice m3 e' simmetrica" : "false: La matrice m3 non e' simmetrica" );
	printf( "%s\n", Mat_is_symmetric(m4) ? "true: La matrice m4 e' simmetrica" : "false: La matrice m4 non e' simmetrica" );
	printf( "%s\n\n", Mat_is_symmetric(m5) ? "true: La matrice m5 e' simmetrica" : "false: La matrice m5 non e' simmetrica" );
	
	printf("La matrice somma di m1 e m2 e'\n\n");
	Mat_print(Mat_sum(m1, m2));
	printf("La matrice somma di m3 e m4 e'\n\n");
	Mat_print(Mat_sum(m3, m4));

	printf("La matrice prodotto di m1 e m2 e'\n\n");
	Mat_print(Mat_product(m1, m2));
	printf("La matrice prodotto di m2 e m4 e'\n\n");
	Mat_print(Mat_product(m2, m4));
	
	printf("Mat max:\n\n");
	Mat_print(Mat_max(m1));
	printf("\n");
	Mat_print(Mat_max(m2));
	printf("\n");
	Mat_print(Mat_max(m3));


	Mat_free(m1);
	Mat_free(m2);
	Mat_free(m3);
	Mat_free(m4);
	Mat_free(m5);	
 	return 0;
}
