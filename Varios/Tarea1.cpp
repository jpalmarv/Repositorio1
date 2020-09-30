#include <iostream>
#include <cmath>


float original(float x);
//float mejor(float x);
float mejor2(float x);

float a = 0.01;

int main(void)
{
  std::cout.precision(8); std::cout.setf(std::ios::scientific);
 
  std::cout << "Grupo:\n";
  std::cout << "Jorge Palmar Velasco\n";
  std::cout << "Jorge Palmar Velasco\n";
  
  for(int  i = 0; i <= 100; ++i){
    float x1 = i*a;
    float f1 = original(x1);
    float f2 = mejor2(x1);
    
    std::cout << x1
	      << "\t" << f1
	      << "\t" << f2
	      << "\n";    
  }
  return 0;
}

float original(float x)
{
  return  5 - std::sqrt( 25 + x*x);
}
float mejor2(float x)
{
  return -1.0*x*x/( 5 + std::sqrt( 25 + x*x));
}

//float mejor(float x)
//{
//x = 5 - std::sqrt( std::pow((x+5),2)-10*x);
  //return x;
//}


  
