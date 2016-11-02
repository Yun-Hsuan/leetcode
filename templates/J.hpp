#include <stdio.h>

template<typename H>
class J{

  public:
    J(): 
      l(0){};
    ~J(){};

    void printl() const;

  private:
    int l;
    int x;

};

//template<typename H>
//void J<H>::printl() const{
//  printf("x: %d\n", l);
//}
//
