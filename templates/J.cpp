#include "J.hpp"

template<typename H>
void J<H>::printl(){
  printf("x: %d\n", 1);
}

template class J<int>;
template class J<double>;
