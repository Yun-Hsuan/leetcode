#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "Block.h"

namespace Uni10{
	
	class Matrix:public Block{
	
		public:

			Matrix& operator=(const Matrix& a);
			//
			Matrix(const Block& a);
			Matrix(const Matrix& a);
			Matrix(rflag uni10_tp, size_t _Rnum, size_t _Cnum);
			Matrix(cflag uni10_tp, size_t _Rnum, size_t _Cnum);
			void setElem(Real* _elem);
			void setElem(Complex* _elem);

			~Matrix();
				
	};

};

#endif
