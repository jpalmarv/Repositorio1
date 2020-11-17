#include <iostream>
#include <cstdlib>
#include <chrono>
#include <omp.h>

double integral(int n, double x, double dx, int nthreads);

int main(int argc, char **argv)
{
  int N = 1000000;
  double low = 0.0;
  double high = 10.0;
  double deltaX = (high - low)/N;
  int NTH = std::atoi(argv[1]);
  
  auto start = std::chrono::steady_clock::now();
  double resultado = integral(N,low,deltaX,NTH);
  auto end = std::chrono::steady_clock::now();

  std::cout.precision(6); std::cout.setf(std::ios::scientific);
  std::cout << resultado << std::endl;
  //std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.0 << "\n";
  
  return 0;
}

double integral(int n, double x, double dx, int nthreads)
{
  double sum = 0.0;
#pragma omp parallel num_threads (nthreads)
  {  
    double sumlocal  = 0.0;
    int nth = omp_get_num_threads();
    int tid = omp_get_thread_num();
    int SL = n/nth;

    for(int ii = tid*SL; ii < tid*SL + SL; ++ii)
      {
	sumlocal += (10.0*ii/n)*(10.0*ii/n)*10/n;
      }
#pragma omp barrier
    sum += sumlocal;    
  }
  return sum;
}
