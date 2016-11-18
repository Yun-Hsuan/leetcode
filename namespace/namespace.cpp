#include <iostream>
using namespace std;

// first name space
namespace first_space{
  void func(){
    cout << "Inside first_space" << endl;
  }

  // second name space
  namespace second_space{
    void func(){
      cout << "Inside second_space" << endl;
    }
  }
}

namespace first_space{

  void func1(){
    cout << "print func2" << endl;
    second_space::func();
  }

}

int main(){

  first_space::func();

  first_space::second_space::func();

  first_space::func1();

  return 0;
}
