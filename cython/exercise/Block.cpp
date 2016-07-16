#include "Block.h"

namespace pyUni10{

	std::ostream& operator<< (std::ostream& os, const pyBlock& b){
		
		os << b.Rnum <<" x " << b.Cnum << "=" << b.elemNum();

		return os;	

	}

	pyBlock::pyBlock(){

		Rnum = 0;
		Cnum = 0;

	}


	pyBlock::pyBlock(size_t _Rnum, size_t _Cnum){

		Rnum = _Rnum;
		Cnum = _Cnum;

		elem = (double*)malloc(sizeof(double)*elemNum());
		memset(elem, 0, sizeof(double)*elemNum());

	}

	size_t pyBlock::elemNum()const{
	
		return Rnum * Cnum;		

	}

	void pyBlock::setElem(double* _elem){
		
		memcpy(elem, _elem, sizeof(double)*elemNum());

	}

	pyBlock::~pyBlock(){
		
		free(elem);

	}

};
