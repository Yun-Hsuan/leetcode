#ifndef ARY_H
#define ARY_H

#include <typeinfo>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <complex>
#include <string.h>

//#define reType double
//typedef reType Type;

class ARY{
	public:
		ARY();
		ARY(size_t r, double* elem);
		ARY(size_t r, std::complex<double>* elem);
		void* getElem() const;
		~ARY();
		void changeType(){
			if(!isReal){
				#undef reType
				#define reType std::complex<double>	
			}else{
				#undef reType
				#define reType double 
			}
		}
		void* operator[](size_t idx);
		/*
		reType& operator[](size_t idx){
			changeType();
			return *((reType*)elem + idx);
		};
		*/
	private:
		bool isReal;
		void* elem;
};
void rewrite();

#endif
