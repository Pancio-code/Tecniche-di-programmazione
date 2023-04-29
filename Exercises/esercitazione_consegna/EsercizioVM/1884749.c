#include "esercizio_1.h"

int max9ij(Mat *m , int i, int j) {
    int cont=0;
    for (int u=i-1; u<=i+1; u++) {
      for (int v=j-1; v<=j+1; v++) {
        if ( (u>=0) && (u< m->rows) && (v>=0) && (v< m->cols) ) 
          if (m->row_ptrs[u][v]==-1) {
		cont+=1;
          }
      }
    }
    return cont;
}

Mat* Mat_alloc(int rows, int cols) {
  Mat* m = (Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (int**)malloc(rows * sizeof(int*));
  for(int i = 0; i < m->rows; ++i) {
    m->row_ptrs[i] = (int*)malloc(m->cols * sizeof(int));
  }
  return m;
}

Mat* campo_minato(Mat* src){
	if(src == NULL) return NULL;
	Mat *m2=Mat_alloc(src->rows, src->cols);
	for(int i = 0; i < src->rows;i++) {
		for(int j = 0; j < src->cols;j++) {
			if( src->row_ptrs[i][j]== -1) m2->row_ptrs[i][j]= -1;
			else m2->row_ptrs[i][j] = max9ij(src,i,j);
		}
	}
  	return m2;
}
