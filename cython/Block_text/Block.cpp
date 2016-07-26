#include "Block.h"

namespace Uni10{

	std::ostream& operator<< (std::ostream& os, const Block& b){
		
		os << b.Rnum <<" x " << b.Cnum << "=" << b.elemNum() << "\n\n";
	
		for(size_t i = 0; (size_t)i < b.Rnum; i++){
			for(size_t j = 0; (size_t)j < b.Cnum; j++){
				os << "  " << b.r_elem[i*b.Cnum+j];
			}
			os << "\n\n";
		}

		return os;	

	}

	Block::Block(){

		Rnum = 0;
		Cnum = 0;

		r_flag = RTYPE;

	}

	Block operator+(const Block& a, const Block& b){
			
		if(a.typeID() == 1 && b.typeID() == 1){
				Block tmp(RTYPE, a.Rnum, a.Cnum);
				double* _elem = (double*)malloc(sizeof(double)*a.elemNum());
				for(int i = 0; i < (int)a.elemNum(); i++){
						_elem[i] = a.r_elem[i] + b.r_elem[i];
						printf("%.5f \n", _elem[i]);
				}
				tmp.setElem(_elem);
				//std::cout << tmp;
				free(_elem);
				return tmp;
	
		}else{
				printf("Not OK!!!!\n");
		}
		return Block();
	}

	Block operator*(Real a, const Block& b){
		
	 if(b.typeID() == 1){
			Block tmp(RTYPE, b.Rnum, b.Cnum);
			double* _elem = (double*)malloc(sizeof(double)*b.elemNum());
			memcpy(_elem, b.r_elem, sizeof(double)*b.elemNum());
			for(size_t i = 0; i < b.elemNum(); i++)
				_elem[i] *= a;
			tmp.setElem(_elem);
			return tmp;
	 }
	 else{
			printf("Not OK !!!!\n");
	 }
	return Block();
	}

	Block::Block(size_t _Rnum, size_t _Cnum){

		Rnum = _Rnum;
		Cnum = _Cnum;

		r_elem = (Real*)malloc(sizeof(Real)*elemNum());
		c_elem = NULL;
		memset(r_elem, 0, sizeof(Real)*elemNum());

		r_flag = RTYPE;
		c_flag = CNULL;

	}

	Block::Block(rflag uni10_tp, size_t _Rnum, size_t _Cnum){

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

	Block::Block(cflag uni10_tp, size_t _Rnum, size_t _Cnum){

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

	void Block::setElem(Real* _elem){
		
		memcpy(r_elem, _elem, sizeof(Real)*elemNum());

	}

	void Block::setElem(Complex* _elem){
		
		memcpy(c_elem, _elem, sizeof(Complex)*elemNum());

	}

	int Block::typeID() const{

		return r_flag + c_flag;

	}

	size_t Block::row(){

		return Rnum;

	}

	size_t Block::col(){

		return Cnum;

	}

	Real* Block::getElem(){
		return r_elem;
	}

	Complex* Block::getElem(cflag uni10_tp ){

		return c_elem;

	}

	Block::~Block(){

		if(r_elem != NULL){
			free(r_elem);
		}
		else{
			free(c_elem);
		}

	}

};
