#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "es5_mat.h"






//////////////////////////////////////utility function implementation
Mat* Mat_alloc(int rows, int cols) {
  Mat* m = (Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (float**)malloc(rows * sizeof(float*));
  for(int i = 0; i < m->rows; ++i) {
    m->row_ptrs[i] = (float*)malloc(m->cols * sizeof(float));
  }
  return m;
}

Mat* Mat_read(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("Errore nell'apertura del file %s... esco!\n", filename);
    fclose(fp);
    return NULL;
  }

  int rows = 0;
  if(fscanf(fp, "%d", &rows) != 1) {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di righe... esco!\n", filename);
    fclose(fp);
    return NULL;
  }
  if(rows == 0) {
    return NULL;
  }

  int cols = 0; 
  if(fscanf(fp, "%d", &cols) != 1) {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di colonne... esco!\n", filename);
    fclose(fp);
    return NULL;
  }
  if(cols == 0) {
    return NULL;
  }

  Mat *m = Mat_alloc(rows, cols);
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      float valore = 0.0f;
      if(fscanf(fp, "%f", &valore) != 1) {
        printf("Errore durante la lettura del file %s, non riesco a leggere tutti gli elementi... esco!\n", filename);
        fclose(fp);
        return NULL;
      }
      m->row_ptrs[r][c] = valore;
    }
  }

  fclose(fp);
  return m;
}

void Mat_print(Mat *m) {
  if(m == NULL) return;
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {
      printf("%lf ", m->row_ptrs[r][c]);
    }
    printf("\n\n");
  }
}

void Mat_write(const char *filename, Mat *m) {
  FILE *fp = fopen(filename, "w");
  if(fp == NULL) {
    printf("Errore nell'apertura del file %s... esco!\n", filename);
    return;
  }
  
  fprintf(fp, "%d ", m->rows);
  fprintf(fp, "%d\n", m->cols);
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {
      fprintf(fp, "%f ", m->row_ptrs[r][c]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
}

void Mat_free(Mat *m) {  
  for(int i = 0; i < m->rows; ++i) {
    free(m->row_ptrs[i]);
  }
  free(m->row_ptrs);
  free(m);
}

////////////////////////////////////////////////////functions to implement
bool  Mat_is_symmetric(Mat *m) {
	for(int i = 0; i < m->rows;i++) {
		for(int j = 0; j < m->cols;j++) {
			if( m->row_ptrs[i][j] != m->row_ptrs[j][i] ) {
				return false;
			}
		}
	}					
  	return true;
}

void Mat_normalize_rows(Mat *m) {
	float cont;
	for(int i = 0; i < m->rows;i++) {
		cont=0;
		for(int j = 0; j < m->cols;j++) {
			cont+= pow( m->row_ptrs[i][j], 2);
		}
		for(int j = 0; j < m->cols;j++) {
			m->row_ptrs[i][j]= m->row_ptrs[i][j] / sqrt(cont);
		}
	}

	return;
}

Mat* Mat_clone(Mat *m) {
	Mat* copy =Mat_alloc( m->rows, m->cols);
	for(int i = 0; i < m -> rows;i++) {
		for(int j = 0; j < m -> cols;j++) {
			copy->row_ptrs[i][j]=m->row_ptrs[i][j];
		}
	}
  	return copy;
}

Mat* Mat_sum(Mat *m1, Mat *m2){
	if( m1->rows != m2->rows || m1->cols != m2->cols ){
		printf("Errore le dimensioni delle tue matrici sono diverse\n\n");
		return NULL;
	}
	Mat *output=Mat_alloc(m1->rows, m1->cols);
	for(int i = 0; i < m1->rows;i++) {
		for(int j = 0; j < m1->cols;j++) {
			output->row_ptrs[i][j]=m1->row_ptrs[i][j] + m2->row_ptrs[i][j];
		}
	}
  	return output;
}


Mat* Mat_product(Mat *m1, Mat *m2){
	if( m1->cols != m2->rows ){
		printf("Errore le dimensioni delle tue matrici non sono compatibili\n\n");
		return NULL;
	}
	Mat *output=Mat_alloc(m1->rows, m2->cols);
	int rr = m1->rows, rc = m2->cols;
    	for (int i=0; i<rr; i++) {
      		for (int j=0; j<rc; j++) {
        		output->row_ptrs[i][j] = 0;
        		for (int k=0; k < m1->cols; k++) {
          			output->row_ptrs[i][j] += m1->row_ptrs[i][k] * m2->row_ptrs[k][j];
        		}
      		}
    	}
  	return output;
}

int max9ij(Mat *m , int i, int j) {
    float l = m->row_ptrs[i][j];
    for (int u=i-1; u<=i+1; u++) {
      for (int v=j-1; v<=j+1; v++) {
        if ( (u>=0) && (u< m->rows) && (v>=0) && (v< m->cols) ) 
          if (m->row_ptrs[u][v]>l) {
		return 0;
          }
      }
    }
    return 1;
}


Mat* Mat_max(Mat *m1) {
	if(m1 == NULL) return NULL;
	Mat *m2=Mat_alloc(m1->rows, m1->cols);
	for(int i = 0; i < m1->rows;i++) {
		for(int j = 0; j < m1->cols;j++) {
			m2->row_ptrs[i][j] = max9ij(m1,i,j);
		}
	}
  	return m2;
}




