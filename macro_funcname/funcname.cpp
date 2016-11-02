#include <stdio.h>

//#define ONE 1
//#define ZERO 0

#define GLUE_HELPER(x, y) x##y
//#define GLUE(x, y) GLUE_HELPER(x, y)

void foo0(int x)
{
      printf("\n foo0...%d\n", x);
}

void foo1(int x)
{
      printf("\n foo1...%d\n",x);
}

void fooBZ0(int x){

      printf("\n fooBZ...%d\n",x);

}

int main()
{
  //Calling Function
  //GLUE(foo,ZERO)(5);    
  //GLUE(foo,ONE)(10);    
  GLUE_HELPER(foo,0)(5);    
  GLUE_HELPER(foo,1)(10);    
  GLUE_HELPER(foo, BZ0)(10);    

  return 0;
     
}
