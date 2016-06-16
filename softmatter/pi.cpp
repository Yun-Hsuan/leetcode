#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

int main(){

	int N= 100000;
	double x,y;
	int i,count;
	double z;
	double pi;

	srand(SEED);
	count = 0;
	for(i=0; i < N; i++){
		x = (double)rand()/RAND_MAX;	
		y = (double)rand()/RAND_MAX;	
		z = x*x + y*y;
		if(z <= 1)
			count++;
		pi = (double)count/N*4;
		fprintf(stderr, "pi = %.10f\n", pi);
	}
	return 0;
}
