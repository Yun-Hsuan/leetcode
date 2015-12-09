#include <iostream>
#include <math.h>

using namespace std;

bool isPowerOfTwo(int n);

bool isPowerOfTwo(int n) {
	double ans = log2(n);
	if(n == 0)
		return false;
	if(floor(ans) != ans)
		return false;
	return true;	        
}

int main(){
	int n = 4;
	if(isPowerOfTwo(n))
		cout << "==================" << endl;
	return 0;
}
