#ifndef __PY_BLOCK_H__
#define __PY_BLOCK_H__

#include <iostream>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double Real;
typedef std::complex<double> Complex;

namespace Uni10{

	class Matrix;

	enum rflag{
		RNULL = 0,
		RTYPE = 1
	};

	enum cflag{
		CNULL = 0,
		CTYPE =	2 
	};

	class Block{

		public:

			friend std::ostream& operator<< (std::ostream& os, const Block& b);
			//friend Block operator*(Real a, const Block& b);
			friend Matrix operator+(const Block& a, const Block& b);

			Block();
			Block(const Block& a);
			Block(rflag uni10_tp, size_t _Rnum, size_t _Cnum);
			Block(cflag uni10_tp, size_t _Rnum, size_t _Cnum);
			//Block(size_t _Rnum, size_t _Cnum);
			size_t elemNum()const;
			int typeID() const;
			size_t row();
			size_t col();
			Real* getElem();
			Complex* getElem(cflag uni10_tp);

			~Block();

	    friend class Matrix;

		protected:
			rflag r_flag;
			cflag c_flag;
			size_t Rnum;
			size_t Cnum;
			Real* r_elem;
			Complex* c_elem;

	};

};

#endif
