from cython.operator cimport dereference as deref
import numpy as np
cimport numpy as np
np.import_array()
from libcpp.complex cimport complex
from cython cimport view

#cimport Block
ctypedef double Real
ctypedef complex[double] Complex


cdef extern from "Block.h" namespace "Uni10":
	
	cdef enum rflag:
		RNULL = 0
		RTYPE = 1

	cdef enum cflag:
		CNULL = 0
		CTYPE = 2

	cdef cppclass Block:
		Block()
		Block(Block )
		Block(rflag uni10_tp, size_t _Rnum, size_t _Cnum)
		Block(cflag uni10_tp, size_t _Rnum, size_t _Cnum)
		size_t elemNum()
		size_t row()
		size_t col()
		int typeID()
		Real* getElem()
		double complex* getElem(cflag uni10_tp);
		Block operator+(Block)

cdef extern from "<iostream>" namespace "std":
	cdef cppclass ostream:
		ostream& operator << (Block)
		
	ostream cout

cdef extern from "Matrix.h" namespace "Uni10":

	cdef cppclass Matrix(Block):
		Matrix(Block )
		Matrix(Matrix )
		Matrix(rflag uni10_tp, size_t _Rnum, size_t _Cnum)
		Matrix(cflag uni10_tp, size_t _Rnum, size_t _Cnum)
		void setElem(Real* _elem)
		void setElem(Complex* _elem)
		Matrix& operator=(Matrix );


cdef class pyBlock:

	cdef Block* _thisptr

	def __cinit__(self, str uni10_tp = 'R', unsigned long _Rnum = 0, unsigned long _Cnum = 0):
			
		if type(self) is pyBlock:
			if uni10_tp == "R":
				#print "Block Constructor"
				self._thisptr = new Block(RTYPE, _Rnum, _Cnum)
			elif uni10_tp == "C":
				self._thisptr = new Block(CTYPE, _Rnum, _Cnum)

	def __dealloc__(self):
		if type(self) is pyBlock and self._thisptr != NULL:
			del self._thisptr

	def __str__(self):
		cout <<  self._thisptr[0]
		return ' '
		#return s
		#os = str(self._thisptr.row()) + ' x ' + str(self._thisptr.col()) + ' = ' + str(self._thisptr.elemNum()) + "\n\n"
		#typeID = self._thisptr.typeID()
		##cdef double* r_elem_ptr = NULL
		##cdef complex[double]* c_elem_ptr = NULL
		#_Rnum = self._thisptr.row()
		#_Cnum = self._thisptr.col()

		#buf_arr = self.getElem()

		#for i in xrange(_Rnum):
		#	for j in xrange(_Cnum):
		#		os += "  " + str(buf_arr[i*_Cnum + j])	
		#	os += '\n\n'

		#return os

	def __add__(pyBlock self, pyBlock rhs):
			
		#print 'Pyadd Block 1 =============='
		#print self
		#print 'Pyadd Block 2 =============='
		#print rhs
		#print 'Pyadd Block 3 =============='

		str_type = 'R'
		if self.typeID() is not 1 or rhs.typeID() is not 1:
			str_type = 'C'
		#print str_type
		#print 'Pyadd Block 4 =============='
		res = pyMatrix(str_type, self._thisptr.row(), self._thisptr.col())
		#del res._thisptr
		res._thisptr_m[0] = self._thisptr[0] + rhs._thisptr[0]
		#print res
		#print 'Pyadd Block 5 =============='
		return res
	
	cpdef unsigned long elemNum(self):
		return self._thisptr.elemNum()

	cpdef long typeID(self):
		return self._thisptr.typeID()
	
	def getElem(self):

		typeID = self._thisptr.typeID()
		elemNum = self._thisptr.elemNum()

		if typeID == 1 :
			return np.asarray(<np.float64_t[:elemNum]> self._thisptr.getElem())

		elif typeID == 2 :
			return np.asarray(<np.complex128_t[:elemNum]> self._thisptr.getElem(CTYPE))


cdef class pyMatrix(pyBlock):

	cdef Matrix* _thisptr_m

	def __cinit__(self, str uni10_tp = 'R', unsigned long _Rnum = 0, unsigned long _Cnum = 0):

		if type(self) is pyMatrix:
			if uni10_tp == "R":
				#print "Matrix Constructor"
				self._thisptr_m = self._thisptr = new Matrix(RTYPE, _Rnum, _Cnum)
			elif uni10_tp == "C":
				self._thisptr_m = self._thisptr = new Matrix(CTYPE, _Rnum, _Cnum)

	def __dealloc__(self):
		if type(self) is pyMatrix and self._thisptr_m != NULL:
			del self._thisptr_m

	cpdef void setElem(self, np.ndarray A):

		arr_type = 0
		if A.dtype == np.float64:
			arr_type = np.float64
		elif A.dtype == np.complex128:
			arr_type = np.complex128
		else:
			print "Type Error !!!!"

		cdef np.ndarray A_buf = A.astype(arr_type, copy=True)

		print A_buf

		if A.dtype == np.dtype(float):
			self._thisptr_m.setElem(<Real*> A_buf.data)
		if A.dtype == np.complex128:
			self._thisptr_m.setElem(<Complex*> A_buf.data)

