#include <iostream>
#include <cmath>


float original(float x);
float mejor(float x);



int main(void)
{
  std::cout.precision(8); std::cout.setf(std::ios::scientific);
 
  std::cout << "Grupo:\n";
  std::cout << "Jorge Palmar Velasco\n";
  std::cout << "Jorge Palmar Velasco\n";

  float a = 0.01;
  
  for(int  ii = 0; ii <= 100; ++ii){
    
    float x1 = ii * a;
    
    std::cout << x1
	      << "\t" << original(x1)
	      << "\t" << mejor(x1)
	      << "\n";    
  }
  return 0;
}

float original(float x)
{
  x =  5 - std::sqrt( 25 + std::pow(x,2));
  return x;
}
float mejor(float x)
{
  x = -1.0*x*x/( 5 + std::sqrt( 25 + x*x));
  return x;
}
