#include "ARY.h"

ARY::ARY(size_t r, double* _elem){
	isReal = true;
	elem = malloc(r*sizeof(double));
	memcpy(elem, _elem, r*sizeof(double));
}

ARY::ARY(size_t r, std::complex<double>* _elem){
	isReal = false;
	elem = malloc(r*sizeof(std::complex<double>));
	memcpy(elem, _elem, r*sizeof(std::complex<double>));
}

void* ARY::getElem() const{
	return elem;
}
void* ARY::operator[](size_t idx){
	if(isReal)
		return ((double*)elem + idx);
	else
		return ((std::complex<double>*)elem + idx);
}

ARY::~ARY(){
	//free(elem);
}

void rewrite(){
	system("pwd");
}

