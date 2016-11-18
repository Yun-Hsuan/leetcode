#include "func.h"

template<typename T>
void printM(T& M, int m, int n){
  
  for(int i =0; i < m; i++){
    for(int j = 0; j < n; j++){
      std::cout << " " << M[i][j];
    }
    std::cout << std::endl;
  }

}

