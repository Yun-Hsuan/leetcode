cdef extern from "Block.h" namespace "pyUni10":

	cdef cppclass pyBlock:

			pyBlock();
			pyBlock(size_t _Rnum, size_t _Cnum);
			size_t elemNum() const;
































