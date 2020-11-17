#include <iostream>
#include <cstdlib>
#include <chrono>
#include <omp.h>

double integral(int n, double x, double dx, int threads);

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
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.0 << "\n";
  
  return 0;
}

double integral(int n, double x, double dx, int threads)
{
    double suma = 0.0;
#pragma omp parallel for num_threads(threads) reduction(+:suma)
  for(int ii = 0; ii < n; ii++){
    suma += (x + ii*dx)*(x + ii*dx);
  }

  return suma*dx;
}
