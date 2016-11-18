#include <stdio.h>

template<typename H>
class J{

  public:
    J(): 
      l(0){};
    ~J(){};

    static void printl();

  private:
    int l;

};

//template<typename H>
//void J<H>::printl() const{
//  printf("x: %d\n", l);
//}
//
