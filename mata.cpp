#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){
  double under = 1.0, over = 1.0;;
  int N = std::atoi(argv[1]);
  //std::cout.presition(15);
  //std::cout.setf(std::ios::scientefics);
  //std::cout << argc<< "\n";
  //std::cout << argv[0] << "\n";
  
  for(int ii = 0; ii < N; ++ii){
    under /= 2.0;
    over *= 2.0;
    std::printf("%8d %10.16e %10.16e\n", ii, under, over);
  }

  return 0;
}
