#include "lattice.h"
#include <algorithm>
#include <chrono>
#include <random>

void vectorMul(int val, double* vec, int len){
	for(int n = 0; n < len; n++)
		vec[n] *= (double)val;
}

double mean(double* vec, int len){
	double arg = 0;
	for(int n = 0; n < len; n++)
		arg += vec[n];
	return arg / (double)len;
}

Lattice::Lattice(){
	conf = NULL;
	arrange = NULL;
}

Lattice::Lattice(unsigned int _L, double _J, double _T):Lh(_L), Lv(_L), J(_J), T(_T){

	Lsize = Lv*Lh;
	int memsize = Lsize*sizeof(spin);
	conf = (spin*)malloc(memsize);
	for(int i = 0; i < Lsize; ++i)
		conf[i] = spin();
	arrange = (int*)malloc(sizeof(int)*Lsize);
	for(int j = 0; j < Lsize; ++j)
		arrange[j] = j;
	
}

Lattice::~Lattice(){
	free(conf);
	free(arrange);
}

int Lattice::len(){
	return Lh;
}

int Lattice::width(){
	return Lv;
}

void Lattice::setT(double _T){
	T = _T;
}

void Lattice::printConf(){
	
	for(int j = 0; j < Lv; j++){
		for(int i = 0; i < Lh; i++)
			printf("%d ", conf[j*Lh+i].S);
		printf("\n");
	}

}

double Lattice::spinH(int i, int j){

	int hb = (i-1+Lh)%Lh;   // bottom (i dir)
	int ht = (i+1+Lh)%Lh;   // top (i dir)
	int vb = (j-1+Lv)%Lv;   // top (i dir)
	int vt = (j+1+Lv)%Lv;   // top (i dir)
	return conf[j*Lh+i].S * J * (conf[j*Lh+hb].S + conf[j*Lh+ht].S + conf[vb*Lh+i].S + conf[vt*Lh+i].S);

}

double Lattice::ExactE(){

	double E0 = 0.;
	for(int i = 0; i < Lh; i++)
		for(int j = 0; j < Lv; j++)
			E0 += spinH(i,j);
	return E0/2.;

}

double Lattice::ExactM(){

	double M0 = 0.;
	for(int i = 0; i < Lh; i++)
		for(int j = 0; j < Lv; j++)
			M0 += conf[j*Lh+i].S;
	return M0;

}

void Lattice::updateSpin(int i, int j){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64 generator(seed);
	std::uniform_real_distribution<double> distribution(0.,1.);
	double randNum = distribution(generator);
	if(spinH(i,j)>0)
		conf[j*Lh+i].flip();
	else if ( randNum < exp(2.0*spinH(i,j)/T))
		conf[j*Lh+i].flip();

}

void Lattice::MonteOpt(int N){
	
	for(int n = 0; n < N; n++){
		//std::random_shuffle(arrange, arrange+Lsize);
		for(int i = 0; i < Lsize; i++)
			updateSpin(arrange[i]%Lh,arrange[i]/Lh);
	}

}
//
//double Lattice::Measure(TypeM label, int BinS, int Nst, int Nbin){
//	
//	int vals[Nbin];
//	int order = label > 1 ? 2 : 1;
//
//	for(int k = 0; k < Nbin; k++){
//		double val = 0;
//	}
//
//	return vals[0];
//
//}
//
void Lattice::Measure(int BinS, int Nst, int Nbin){
	
	double Es[Nbin], Ms[Nbin], E2s[Nbin], M2s[Nbin], M4s[Nbin];
	for(int k = 0; k < Nbin; k++){
		double E = 0., M = 0., E2 = 0., M2 = 0., M4 = 0.;
		for(int i = 0; i < BinS; i++){
			this->MonteOpt(Nst);
			double Ei = this->ExactE();
			double Mi = fabs(this->ExactM());
			E += Ei;
			M += Mi;
			E2 += Ei*Ei;
			M2 += Mi*Mi;
			M4 += pow(Mi,4.);
		}
		Es[k] = E / BinS / (double)Lsize;
		Ms[k] = M / BinS / (double)Lsize;
		E2s[k] = E2 / BinS / (double)pow(Lsize,2.);
		M2s[k] = M2 / BinS / (double)pow(Lsize,2.);
		M4s[k] = M4 / BinS / (double)pow(Lsize,4.);
	}
	//vectorMul(Lsize, E2s, Nbin);	
	//vectorMul(Lsize, M2s, Nbin);	
	vals.valE = mean(Es, Nbin);
	vals.valM = mean(Ms, Nbin);

}

contain Lattice::getVals(){
	return vals;
}
