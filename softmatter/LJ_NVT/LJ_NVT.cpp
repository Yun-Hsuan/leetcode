#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CubicGrid.h"

int main(){

	int nPart = 200; //number of particles
	double density = 0.5; //Density of particlas
	double T = 2.0;	 //Temperature
	double beta = 1./T;
	double maxDr = 0.1; // Maximal displacement

	int N = 9000;
	int print = 100;

	char xyzfile[] = "LJ_NVT.xyz";

	Cubic LJ_NVT3D(nPart, density, beta);
	//double E = LJ_NVT3D.LJ_Energy();
	printf("N,E\n");
	LJ_NVT3D.MonteOpt(N, maxDr, print);
	LJ_NVT3D.writeXYZ(xyzfile);

	//	
	//MC simulation
	//
	
	return 0;
}
