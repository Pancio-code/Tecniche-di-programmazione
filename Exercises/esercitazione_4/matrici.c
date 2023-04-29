#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int rows; 
  int cols;
  float **row_ptrs;
} Mat;

Mat* Mat_alloc(int rows, int cols);
Mat* Mat_read(const char *filename);
void Mat_dealloc(Mat* m);

int main(int argc, char **argv) {
	for(int i=1 ; i < argc ; i++) {
		Mat* m1= Mat_read(argv[i]);
		printf("La matrice del file %s e':\n\n",argv[i]);
		printf("%d %d\n\n",m1 -> rows,m1 -> cols);		
		for(int i = 0; i < m1 -> rows;i++) {
			for(int k = 0; k < m1 -> cols ;k++) {
				printf("%2f ",m1 -> row_ptrs[i][k]);
			}
			printf("\n");
		}
		printf("\n\n");
		Mat_dealloc(m1);
	}			
  return 0;
}

Mat* Mat_alloc(int rows, int cols) {
  	Mat* n =(Mat *)malloc(sizeof(Mat));;
  	n -> rows= rows ;
	n -> cols = cols;
	float** matrice = (float **)malloc((n -> rows)*sizeof(float *));
	for(int i=0; i < n -> rows; i++) {
		matrice[i]=(float *)malloc((n -> cols)*sizeof(float));
	}
	n -> row_ptrs = matrice;	
  	return n;
}

Mat* Mat_read(const char *filename) {
	int r, c;
	float elem;
  	FILE* pfile =fopen(filename,"r");
	if (pfile == NULL){
		printf("Errore nell'apertura del file\n");
		exit(1);
	}
	fscanf(pfile,"%d",&r);
	fscanf(pfile,"%d",&c);
	Mat *m=Mat_alloc(r, c);
	for(int i=0; i < r ;i++) {
		for(int k=0; k < c ;k++) {
			fscanf(pfile,"%f",&elem);
			m -> row_ptrs[i][k] = elem;
		}
	}
	int close = fclose(pfile);
	if ( close == EOF) {
		printf("Errore nella chiusura del file\n");
		exit(1);
	}
  return m;
}

void Mat_dealloc(Mat* m) {
	for(int i=0; i < m -> rows; i++) {
		free(m -> row_ptrs[i]);
	}
	free(m -> row_ptrs);
	free(m);
	return;
}
	

