#ifndef __HEADER_H__
#define __HEADER_H__

#define M_PI 3.1415926
#define MAX(a, b) ((a) >= (b) ? (a): (b))

double hypot(double, double);

typedef int uni10_int_t;
typedef double uni10_double;

void func(uni10_int_t, uni10_int_t, uni10_double);

uni10_double *func_arrays(uni10_int_t[], uni10_int_t[][10], uni10_double**);

#endif
