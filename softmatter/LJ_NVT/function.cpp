#include "function.h"

double vecSqrDis(std::vector<double>& drvec){
	
	double sqrDis = 0;
	for(int i = 0; i < (int)drvec.size(); i++)
		sqrDis += drvec[i] * drvec[i];

	return sqrDis;
}

void dist3DPBC(std::vector<double>& drvec, int L, int dim){

	double halfL = L/2.0;
	for(int i = 0; i < dim; i++){
		if(drvec[i] > halfL){
			drvec[i] -= L;
		}else if(drvec[i] < -halfL){
			drvec[i] += L;
		}
	}
}

void PB3D(std::vector<double>& drvec, int L, int dim){

	for(int i = 0; i < dim; i++){
		if(drvec[i] > L){
			drvec[i] -= L;
		}else if(drvec[i] < 0){
			drvec[i] += L;
		}
	}

}
