#include <iostream>
#include <cmath>

void printBool(bool isWin);
bool canWinNim(int n);

bool canWinNim(int n){
	return n%4 != 0;
}

void printBool(bool isWin){
	if(isWin)
		std::cout << "true"<< std::endl;
	else
		std::cout << "flase"<< std::endl;
}

int main(){
	int Num = 4;
	printBool( canWinNim(Num) );
	return 0;
}
