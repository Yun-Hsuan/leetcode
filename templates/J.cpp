#include "J.hpp"

template<typename H>
void J<H>::printl() const{
  printf("x: %d\n", l);
}

template class J<int>;
template class J<double>;
