#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float** Mat_alloc(int rows, int cols);
float** Mat_read(const char *filename);
void Mat_dealloc(float** m,int righe);

int main(int argc, char **argv) {
	for(int i=1 ; i < argc ; i++) {
		float** m1= Mat_read(argv[i]);
		int r, c;
  		FILE* pfile =fopen(argv[i],"r");
		if (pfile == NULL){
			printf("Errore nell'apertura del file\n");
			exit(1);
		}
		fscanf(pfile,"%d",&r);
		fscanf(pfile,"%d",&c);
		int close = fclose(pfile);
		if ( close == EOF) {
			printf("Errore nella chiusura del file\n");
			exit(1);
		}
		printf("La matrice del file %s e':\n\n",argv[i]);
		printf("%d %d\n\n",r,c);		
		for(int i = 0; i < r;i++) {
			for(int k = 0; k < c ;k++) {
				printf("%2f ",m1[i][k]);
			}
			printf("\n");
		}
		printf("\n\n");
		Mat_dealloc(m1,r);
	}			
  return 0;
}

float** Mat_alloc(int rows, int cols) {
	float** matrice = (float **)malloc((rows)*sizeof(float *));
	for(int i=0; i < rows; i++) {
		matrice[i]=(float *)malloc((cols)*sizeof(float));
	}	
  	return matrice;
}

float** Mat_read(const char *filename) {
	float elem;
  	FILE* pfile =fopen(filename,"r");
	if (pfile == NULL){
		printf("Errore nell'apertura del file\n");
		exit(1);
	}
  	int r = 0;
  	if(fscanf(pfile, "%d", &r) != 1) {
    		printf("Errore durante la lettura del file %s, non riesco a leggere il numero di righe... esco!\n", filename);
    		fclose(pfile);
    		return NULL;
  	}
  	if(r == 0) {
    		return NULL;
  	}

  	int c = 0; 
  	if(fscanf(pfile, "%d", &c) != 1) {
    		printf("Errore durante la lettura del file %s, non riesco a leggere il numero di colonne... esco!\n", filename);
    		fclose(pfile);
    		return NULL;
  	}
  	if(c == 0) {
    		return NULL;
  	}
	//fscanf(pfile,"%d",&r);
	//fscanf(pfile,"%d",&c);
	float** m=Mat_alloc(r, c);
	for(int i=0; i < r ;i++) {
		for(int k=0; k < c ;k++) {
			fscanf(pfile,"%f",&elem);
			m[i][k] = elem;
		}
	}
	int close = fclose(pfile);
	if ( close == EOF) {
		printf("Errore nella chiusura del file\n");
		exit(1);
	}
  return m;
}

void Mat_dealloc(float** m,int righe) {
	for(int i=0; i < righe; i++) {
		free(m[i]);
	}
	free(m);
	return;
}

