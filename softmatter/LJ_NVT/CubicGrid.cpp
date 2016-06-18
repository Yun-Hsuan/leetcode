#include "CubicGrid.h"
#include "function.h"
#include <iostream>

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 generator(seed);
std::uniform_real_distribution<double> distribution(0.,1.);

Cubic::Cubic(){
	x = 0;	
	y = 0;	
	z = 0;	
	beta = 0;
	energy = 0.;
}

Cubic::Cubic(int nPart, double density, double _beta){

  beta = _beta;
  energy = 0.;
  std::vector<double> buf(3);
  coords.assign(nPart, buf);
  
  //std::cout << nPart/density << std::endl;
  L = pow(nPart/density, 1./3.);

  int nSubCube = 2;
  while(pow(nSubCube, 3) < nPart)
    nSubCube += 1;

  std::vector<double> indexOld(3);
  std::vector<double> indexNew(3);
  //std::vector<double> index(3);

  // Assign particle position

  for(int i = 0; i < nPart; i++){

    for(int j = 0; j < (int)indexOld.size(); j++)
      indexNew[j] = (indexOld[j] + 0.5) * (L/nSubCube);

    coords[i] = indexNew;
    indexOld[0] += 1; 
    if(indexOld[0] > L){
      indexOld[0] = 0;
      indexOld[1] += 1;
      if(indexOld[1] > L){
	indexOld[1] = 0;
	indexOld[2] += 1;
      }
    }
  }
}

Cubic::~Cubic(){

}

std::vector<std::vector<double> > Cubic::getCoords(){
  return coords;
}

double Cubic::getL(){
  return L;
}

double Cubic::LJ_Energy(){

  double ljenergy = 0;
  int nPart = coords.size();

  for(int i = 0; i < nPart-1; ++i){
    for(int j = i+1; j < nPart; ++j){
      //Calculate particle-particle boundary distance
      std::vector<double> drvec(3);
      for(int k = 0; k < (int)drvec.size(); k++)
	drvec[k] = coords[i][k] - coords[j][k];

      dist3DPBC(drvec, L, coords[0].size());	
      double D2 = vecSqrDis(drvec);
      double invD6 = 1.0 / (pow(D2, 3.));
      ljenergy += (invD6 * (invD6 - 1.));

    }
  }

  return ljenergy*4.;

  return 0;
}

double Cubic::LJ_EnergyChang(std::vector<double>& vecTrial, int idx){
  double deltaE = 0.;
  int nPart = coords.size();
  int dim = coords[0].size();

  for(int i = 0; i < nPart; i++){

    if(i == idx) 
      continue;

    std::vector<double> NewDr(3);
    std::vector<double> OldDr(3);

    for(int j = 0; j < (int)NewDr.size(); j++){
      NewDr[j] = coords[i][j] - vecTrial[j];
      OldDr[j] = coords[i][j] - coords[idx][j];
    }

    dist3DPBC(NewDr, L, dim);
    dist3DPBC(OldDr, L, dim);

    double dr2_New = vecSqrDis(NewDr);
    double dr2_Old = vecSqrDis(OldDr);

    double invD6_New = 1.0 / (pow(dr2_New,3.));
    double invD6_Old = 1.0 / (pow(dr2_Old,3.));

    double NewEng = invD6_New * (invD6_New - 1);
    double OldEng = invD6_Old * (invD6_Old - 1);

    deltaE += (NewEng - OldEng);
  }

  return deltaE*4.;
}

void Cubic::MonteOpt(int N, double maxDir, int print){

  energy = LJ_Energy();

  for(int n = 0; n < N; ++n){

    int nPart = coords.size();
    std::vector<double> trialIdx(3);

    for(int i = 0; i < nPart; ++i){

      for(int j = 0; j < (int)trialIdx.size(); ++j)
	trialIdx[j] = coords[i][j] + maxDir*(distribution(generator)-0.5);

      PB3D(trialIdx, L, coords[0].size());

      double deltaE = LJ_EnergyChang(trialIdx, i);

      if(distribution(generator) < exp(-beta*deltaE)){
	coords[i] = trialIdx;
	energy += deltaE;
      }
    }

    if(print != 0 && n % print == 0){
      char filename[64] = "xyz/LJ_NVT";
      char buf[12];
      sprintf(buf, "%d.xyz", n/print);
      strcat(filename, buf);
      printf("%d,%.8f\n", n, energy);
      writeXYZ(filename);
    }
  }
}

void Cubic::writeXYZ(char* filename){

  FILE* fp = fopen(filename, "w");
  fprintf(fp, "%ld\n\n", coords.size());
  for(int i = 0; i < (int)coords.size(); i++)
    fprintf(fp,"A %.5f %.5f %.5f\n", coords[i][0],coords[i][1],coords[i][2]);
  fclose(fp);
}

double Cubic::getE(){
  return energy;
}

