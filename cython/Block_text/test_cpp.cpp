#include "Matrix.h"

using namespace std;
using namespace Uni10;

int main(){
	
	double elem[] = {2.0, 3.2, 1.0, 3.4};
	Matrix A(RTYPE, 2, 2);
	A.setElem(elem);
	cout << "========= Block A ========" << endl;
	cout << A;
	Matrix B = A;
	cout << "========= Block B ========" << endl;
	cout << B;
	cout << "========= Block C ========" << endl;
	cout << A + B;
	cout << "========= Block D ========" << endl;
	Matrix C = A + B;
	cout << C;
	return 0;
}
