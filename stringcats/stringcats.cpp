#include <stdio.h>
#include <stdlib.h>

void func(char** terms, size_t* nums = NULL);

void func(char*[4] terms, size_t* nums){

}

int main(){

  const char* const A[3] = {"Hellow", "Rocket", "!!!!"};
  size_t B[2] = {312, 231};

  func(A);

  printf("%s\n", A[0]);
  printf("%s\n", A[1]);
  printf("%s\n", A[2]);
  
  return 0;
}
