#include <iostream>
#include <cmath>


float original(float x);
float mejor(float x);
float mejor2(float x);

int main(void)
{
  std::cout.precision(8); std::cout.setf(std::ios::scientific);
 
  std::cout << "Grupo:\n";
  std::cout << "Jorge Palmar Velasco\n";
  std::cout << "Jorge Palmar Velasco\n";

  for(float ii = 0.00; ii <= 1.00; ii += 0.01){
    std::cout << ii
	      << "\t" << original(ii)
	      << "\t" << mejor(ii)
	      << "\n";    
  }
  return 0;
}

float original(float x)
{
  x = 5 - std::sqrt( 25 + std::pow(x,2));
  return x;
}

float mejor(float x)
{
  x = 5 - std::sqrt( std::pow((x+5),2)-10*x);
  return x;
}

float mejor2(float x)
{
  x = -(std::sqrt( 25 + std::pow(x,2)) - 5);
  return x;
}
  
