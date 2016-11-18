#include <stdio.h>
#include <iostream>

int max(int* a, int* b){

  std::cout << a << std::endl;
  *a = 3;

  return *a < *b ? *b : *a;
}

int max(int& a, int& b){

  std::cout << &a << std::endl;
  a = 3;

  return a < b ? b : a;
}

int main(){

  int a = 1;
  int b = 2;

  std::cout << &a << std::endl;

  max(a, b);



  //printf("a: %d\n", max(&a, &b));
  //printf("max: %d\n", max(&a, &b));

  return 0;
}
