#ifndef LATTICE_H
#define LATTICE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct spin{
	spin(int _S = 1.0){S = _S;};
	void flip(){S *= -1;};
	double S;
};

struct contain{

	contain(){valE = 0; valM = 0; valE2 = 0; valM2 = 0;};
	double valE, valM, valE2, valM2;

};

//enum TypeM{
// E = 0,
// M = 1,
// E2 = 2,
// M2 = 3,
//};

void vectorMul(int val, double* vec, int N);
double mean(double* vec, int len);

class Lattice{
	
	public:

		Lattice();
		Lattice(unsigned int _L, double _J = -1.0, double _T = 2.5);
		~Lattice();
		void printConf();
		int len();
		int width();
		void setT(double _T);
		double spinH(int i, int j);
		double ExactE();
		double ExactM();
		void updateSpin(int i , int j);
		void MonteOpt(int N);
		//double Measure(TypeM label, int BinS, int Nst, int Nbin);
		void Measure(int BinS, int Nst, int Nbin);
		contain getVals();

	private:

		int Lh;
		int Lv;
		int Lsize;
		double J;
		double T;
		spin* conf;
		contain vals;
		int* arrange;

};

#endif
