#include "pyBlock.h"

using namespace std;
using namespace pyUni10;

int main(){

	size_t row = 20, col = 10;	
	pyBlock  A(row, col);

	cout << A;
	
	return 0;
}
