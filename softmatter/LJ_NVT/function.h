#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>

void dist3DPBC(std::vector<double>& drvec, int L, int dim);
void PB3D(std::vector<double>& drvec, int L, int dim);
double vecSqrDis(std::vector<double>& drvec);

#endif
