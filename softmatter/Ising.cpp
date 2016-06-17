#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "lattice.h"

using namespace std;

int main(){
	
	Lattice L(16);
	//printf("E0: %10f\n", L.ExactE());
	//L.printConf();	
	printf("T,E,M\n");
	for(int T = 500; T >= 0; T-=10){
		L.setT((double)T/100.);
		L.MonteOpt(200);
		L.Measure(100,1,100);
		printf("%.2f,%.10f,%.10f\n", double(T)/100., L.getVals().valE, L.getVals().valM);
	}

	return 0;
}
