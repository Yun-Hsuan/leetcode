#ifndef CUBICGID_H
#define CUBICGID_H

#include <math.h>
#include <string.h>
#include <vector>
#include <random>
#include <chrono>

class Cubic{

	public:
		Cubic();
		Cubic(int nPart, double density, double _beta);
		~Cubic();
		std::vector<std::vector<double> > getCoords();
		double LJ_Energy();
		double LJ_EnergyChang(std::vector<double>& vecTrail, int idx);
		double getL();
		double getE();
		void MonteOpt(int N, double maxDir, int print);
		void writeXYZ(char* filename);

	private:
		double x, y, z;
		std::vector< std::vector<double> > coords;
		double L;
		double beta;
		double energy;
};

#endif
