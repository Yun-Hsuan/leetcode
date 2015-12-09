#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
using namespace std;
#include "tools/ARY.h"

/*
void *func_t(void *i1, void *i2)
{
	void *retval = malloc(sizeof(int));
	*(int*) retval = *(int*)i1 + *(int*)i2;
	return retval;
}
*/

int main(void){
	#ifdef Linux 
		cout << "OS is Linux" << endl;
	#endif
	double el[4] = {1.0, 3.0, 3.0, 5.0};
	complex<double> e2[4] = {complex<double>(1.0, 1.0),complex<double>(10.0, 1.0),complex<double>(3.0, 1.0),complex<double>(5.0, 0.0)};
	
	ARY a(4, el);
	ARY b(4, e2);
	rewrite();

	for(int i = 0; i < 4; i++)
		printf("%f\n", ((double*)a.getElem())[i]);

	*(double*)a[0] = 4.0 ;

	for(int i = 0; i < 4; i++)
		printf("%f\n", ((double*)a.getElem())[i]);

	for(int i = 0; i < 4; i++)
		cout << ((complex<double>*)b.getElem())[i] << endl;

	*(std::complex<double>*)b[2] =complex<double>(4.0, 1.0);

	for(int i = 0; i < 4; i++)
		cout << ((complex<double>*)b.getElem())[i] << endl;

	/*
	void* (*vfunc)(void *, void*);
	vfunc = func_t;

	int value1 = 100;
	int value2 = 2;
	void* sumvoid = vfunc(&value1, &value2);
	int sum = *(int*)sumvoid;
	free(sumvoid);
	printf("the value of sum is now %d\n", sum);
	*/
	return 0;
}
