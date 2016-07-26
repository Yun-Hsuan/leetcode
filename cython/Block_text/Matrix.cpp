#include "Matrix.h"

namespace Uni10{

	Matrix& Matrix::operator=(const Matrix& a){

		if(r_elem != NULL){
			free(r_elem);
			r_elem = NULL;
		}
		if(c_elem != NULL){
			free(c_elem);
			c_elem = NULL;
		}

		Rnum = a.Rnum;
		Cnum = a.Cnum;
		r_flag = a.r_flag;
		c_flag = a.c_flag;
		r_elem = NULL;
		c_elem = NULL;

		if( typeID() == 1){
			r_elem = (double*)malloc(sizeof(double)*Rnum*Cnum);
			setElem(a.r_elem);
		}
		else{
			c_elem = (Complex*)malloc(sizeof(Complex)*Rnum*Cnum);
			setElem(a.c_elem);
		}

		//std::cout << "$$$$$$$$$" << std::endl;
	 	//std::cout << *this;
		//std::cout << "$$$$$$$$$" << std::endl;

		return *this;
		
	}

	Matrix::Matrix(const Block& a){

		Rnum = a.Rnum;
		Cnum = a.Cnum;
		r_flag = a.r_flag;
		c_flag = a.c_flag;
		r_elem = NULL;
		c_elem = NULL;

		if( typeID() == 1){
			r_elem = (double*)malloc(sizeof(double)*Rnum*Cnum);
			setElem(a.r_elem);
		}
		else{
			c_elem = (Complex*)malloc(sizeof(Complex)*Rnum*Cnum);
			setElem(a.c_elem);
		}
 
	}

	Matrix::Matrix(const Matrix& a){

		Rnum = a.Rnum;
		Cnum = a.Cnum;
		r_flag = a.r_flag;
		c_flag = a.c_flag;
		r_elem = NULL;
		c_elem = NULL;

		if( typeID() == 1){
			r_elem = (double*)malloc(sizeof(double)*Rnum*Cnum);
			setElem(a.r_elem);
		}
		else{
			c_elem = (Complex*)malloc(sizeof(Complex)*Rnum*Cnum);
			setElem(a.c_elem);
		}

	}


	Matrix::Matrix(rflag uni10_tp, size_t _Rnum, size_t _Cnum){

		if(uni10_tp == RNULL){
			printf("FLAG ERROR !!!");
			exit(0);
		}

		Rnum = _Rnum;
		Cnum = _Cnum;

		r_elem = (Real*)malloc(sizeof(Real)*elemNum());
		c_elem = NULL;
		memset(r_elem, 0, sizeof(Real)*elemNum());

		r_flag = RTYPE;
		c_flag = CNULL;

	}

	Matrix::Matrix(cflag uni10_tp, size_t _Rnum, size_t _Cnum){

		if(uni10_tp == CNULL){
			printf("FLAG ERROR !!!");
			exit(0);
		}

		Rnum = _Rnum;
		Cnum = _Cnum;

		r_elem = NULL;
		c_elem = (Complex*)malloc(sizeof(Complex)*elemNum());
		memset(c_elem, 0, sizeof(Complex)*elemNum());

		r_flag = RNULL;
		c_flag = CTYPE;

	}
	size_t Block::elemNum()const{

		return Rnum * Cnum;		

	}

	void Matrix::setElem(Real* _elem){
		
		memcpy(r_elem, _elem, sizeof(Real)*elemNum());

	}

	void Matrix::setElem(Complex* _elem){
		
		memcpy(c_elem, _elem, sizeof(Complex)*elemNum());

	}

	Matrix::~Matrix(){

		if(r_elem != NULL){
			free(r_elem);
		}
		if(c_elem != NULL){
			free(c_elem);
		}

	}



}

