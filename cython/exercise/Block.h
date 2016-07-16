#ifndef __PY_BLOCK_H__
#define __PY_BLOCK_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace pyUni10{

	class pyBlock{

		public:

			friend std::ostream& operator<< (std::ostream& os, const pyBlock& b);

			pyBlock();
			pyBlock(size_t _Rnum, size_t _Cnum);
			size_t elemNum()const;
			void setElem(double* _elem);

			~pyBlock();

		private:

			size_t Rnum;
			size_t Cnum;
			double* elem;

	};

};

#endif
