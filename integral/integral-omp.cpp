#include<iostream>
#include<omp.h>
#include<cstdlib>
#include<cmath>
#include<chrono>

double integral_parallel(int nthreads,int n );
double integral_pragmafor(int nthreads,int n );
void print_elapsed(auto start, auto end);

int main(int argc, char **argv)
{
  const int N = 1000000;
  const int NTH = std::atoi(argv[1]);

  auto start = std::chrono::steady_clock::now();
  integral_parallel(NTH, N);
  auto end = std::chrono::steady_clock::now();
  print_elapsed(start, end);

  start = std::chrono::steady_clock::now();
  integral_pragmafor(NTH, N);
  end = std::chrono::steady_clock::now();
  print_elapsed(start, end);
  
  return 0;
}

double integral_parallel(int nthreads, int n)
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

double integral_pragmafor(int nthreads, int n)
{
  double sum  = 0.0;
#pragma omp parallel for  num_threads (nthreads) reduction(+:sum)
  for(int ii = 0; ii < n; ++ii)
    {
      sum += (10.0*ii/n)*(10.0*ii/n)*10/n;
    }
  return sum;
}

void print_elapsed(auto start, auto end)
{
  std::cout.precision(6); std::cout.setf(std::ios::scientific);
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "\n";
}
