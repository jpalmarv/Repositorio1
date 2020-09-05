#include <iostream>
#include <cmath>
//Se quiere calcular f(x)=5-sqrt(25+x²) para x=0 hasta 1 con pasos de 0.01.
//Se trata de encontrar una forma que evite el error de resta.
//Se encuentra la forma alternativa de la funcón f(x)=-x²/(5+sqrt(25+x²)).

float original(float x);
float mejor(float x);

int main(void)
{
  std::cout.precision(8); std::cout.setf(std::ios::scientific);
 
  std::cout << "Grupo: Sergio Lopez, Jorge Palmar.\n\n";

  for(int ii = 0; ii <= 100; ++ii)
  {
    float x1 = ii * 0.01;
   
    std::cout << x1
	            << "\t" << original(x1)
	            << "\t" << mejor(x1)
              << "\n";
	 }
  return 0;
}
//Se implementa f(x)=5-sqrt(25+x²).
float original(float x)
{
  float Fun;
  Fun =  5 - std::sqrt(25 + x*x);
  return Fun;
}
//Se implementa f(x)=-x²/(5+sqrt(25+x²)).
float mejor(float x)
{
  float Fun;
  Fun = -x*x/( 5 + std::sqrt(25 + x*x));
  return Fun;
}
