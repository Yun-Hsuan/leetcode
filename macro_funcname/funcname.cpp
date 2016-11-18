#include <stdio.h>
#include <random>
#include <chrono>
#include <iostream>
#include <complex>

// engines
#define uni10_mt19937           std::mt19937
#define uni10_mt19937_64        std::mt19937_64
#define uni10_default           std::default_random_engine
#define uni10_ranlux24          std::ranlux24
#define uni10_ranlux48          std::ranlux48
#define uni10_minstd            std::minstd_rand

// distributions
#define uni10_uniform_real           std::uniform_real_distribution< double >
#define uni10_uniform_int            std::uniform_int_distribution< int >
#define uni10_normal                 std::normal_distribution< double >
#define uni10_student_t              std::std::student_t_distribution<double>
#define uni10_lognormal              std::lognormal_distribution<double>
//#define uni10_exp                    std::exponential_distribution< double >
//#define uni10_chi_squared            std::chi_squared_distribution< double >
//typedef std::chrono::system_clock::now().time_since_epoch().count   uni10_uniform;

//typedef std::mt19937                           uni10_mt19937;
//typedef std::uniform_real_distribution<double> uni10_uniform;

#define GLUE_HELPER(x, y) x##y
#define GLUE(x, y) GLUE_HELPER(x, y)

#define uni10_rand(elem, elemNum, eng, dis, seed, up, dn)\
do{ eng generator(seed);\
  dis distribution(up, dn);\
  for(long long int i = 0; i < elemNum; i++)\
    elem[i] = distribution(generator);}\
while(0);

#define uni10_seed 

int main()
{

  std::complex<double> elem[10];
  int elemNum = 10;
  int up_bond = -1.;
  int dn_bond = 1.;
  int seed = 0;   //if 0

  for(int i = 0; i < elemNum; i++)
    std::cout << elem[i] << " ";
  std::cout << std::endl;

  uni10_rand( elem, elemNum, uni10_minstd, uni10_lognormal, seed, up_bond, dn_bond);

  for(int i = 0; i < elemNum; i++)
    std::cout << elem[i] << " ";
  std::cout << std::endl;

  return 0;
     
}
