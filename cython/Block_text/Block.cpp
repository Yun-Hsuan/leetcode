#include "Matrix.h"
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
		c_flag = CNULL;

		r_elem = NULL;
		c_elem = NULL;

	}

	Block::Block(const Block& a){

		Rnum = a.Rnum;
		Cnum = a.Cnum;

		r_flag = a.r_flag;
		c_flag = a.c_flag;

		r_elem = a.r_elem;
		c_elem = a.c_elem;

	}

	Block::Block(rflag uni10_tp, size_t _Rnum, size_t _Cnum){

		Rnum = _Rnum;
		Cnum = _Cnum;

		r_flag = RTYPE;
		c_flag = CNULL;

		r_elem = NULL;
		c_elem = NULL;

		
	}

	Block::Block(cflag uni10_tp, size_t _Rnum, size_t _Cnum){

		Rnum = _Rnum;
		Cnum = _Cnum;

		r_flag = RNULL;
		c_flag = CTYPE;

		r_elem = NULL;
		c_elem = NULL;

	}

 	Matrix operator+(const Block& a, const Block& b){
			
		if(a.typeID() == 1 && b.typeID() == 1){
				Matrix tmp(RTYPE, a.Rnum, a.Cnum);
				double* _elem = (double*)malloc(sizeof(double)*a.elemNum());
				for(int i = 0; i < (int)a.elemNum(); i++){
						_elem[i] = a.r_elem[i] + b.r_elem[i];
						//printf("%.5f \n", _elem[i]);
				}
				tmp.setElem(_elem);
				//std::cout << "hahahah!!!!!!!!!" << std::endl;
				//std::cout << tmp;
				//std::cout << "hahahah!!!!!!!!!" << std::endl;
				free(_elem);
				return tmp;
	
		}else{
				printf("Not OK!!!!\n");
				exit(0);
		}
		return Block();
	}

	//Block operator*(Real a, const Block& b){
	//	
	// if(b.typeID() == 1){
	//		Block tmp(RTYPE, b.Rnum, b.Cnum);
	//		double* _elem = (double*)malloc(sizeof(double)*b.elemNum());
	//		memcpy(_elem, b.r_elem, sizeof(double)*b.elemNum());
	//		for(size_t i = 0; i < b.elemNum(); i++)
	//			_elem[i] *= a;
	//		tmp.setElem(_elem);
	//		return tmp;
	// }
	// else{
	//		printf("Not OK !!!!\n");
	// }
	//return Block();
	//}

	//Block::Block(size_t _Rnum, size_t _Cnum){

	//	Rnum = _Rnum;
	//	Cnum = _Cnum;

	//	r_elem = (Real*)malloc(sizeof(Real)*elemNum());
	//	c_elem = NULL;
	//	memset(r_elem, 0, sizeof(Real)*elemNum());

	//	r_flag = RTYPE;
	//	c_flag = CNULL;

	//}

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

	}

};
