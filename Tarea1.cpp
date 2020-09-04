#include <iostream>
#include <cmath>

     
float original(float x);
float mejor(float x);

int main(void)
{
  std::cout.precision(8); std::cout.setf(std::ios::scientific);

  for(float ii = 0; ii <= 1; ii = ii + 0.01){
    std::cout << ii << "\t" << original(ii) << "\n";
	      
  }
  return 0;
}

float original(float x)
{
  x = 5 - std::sqrt( 25 - std::pow(x,2));
  return x;
}
