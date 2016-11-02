#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//void printMat(double* mat, size_t row, size_t col);
void printMat(double** mat, size_t row, size_t col);
void** Malloc2Darray(size_t row, size_t col, char type);

void printMat(double** mat, size_t row, size_t col){
  size_t i, j;
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++)
      printf("%.4f   ", mat[i][j]);
    printf("\n\n");
  }
}
/*
void printMat(double* mat, size_t row, size_t col){
  for(size_t i = 0; i < row; i++){
    for(size_t j = 0; j < col; j++)
      printf("%.4f   ", mat[i*col + j]);
    printf("\n\n");
  }
}
*/
void** Malloc2Darray(size_t row, size_t col, char type){
  void** mem = (void**)malloc(row*sizeof(double*)); 
  size_t i = 0;
  for(; i < row; i++)
    mem[i] = malloc(col*sizeof(double));
  return mem;
}

int main(){
#if ongpu
  int i;
  for(i = 0 ; i < ongpu; i++)
    printf("=======2==========\n");
#endif
  double** prob = (double**)Malloc2Darray(2, 4, 'd');
  double* test = (double*)malloc(sizeof(double)*4);
  test[0] = 1.0;
  test[1] = 2.2;
  test[2] = 2.3;
  test[3] = 2.1;

  double* test2 = (double*)malloc(sizeof(double)*4);
  test2[0] = 1.1;
  test2[1] = 2.3;
  test2[2] = 2.2;
  test2[3] = 2.34;

  memcpy(prob[0], test, sizeof(double)*4);
  memcpy(prob[1], test2, sizeof(double)*4);

  printMat(prob, 2, 4);
  return 0;
}
