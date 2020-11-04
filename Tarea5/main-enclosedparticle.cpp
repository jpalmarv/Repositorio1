#include "enclosedparticle-simul.h"
#include <string>
#include <fstream>

int main(void)
{
  Particle ball;

  // start system
  initial_conditions(ball);
  compute_force(ball, 0.0);
  start_integration(ball, DT);
  print(ball, 0.0);

  // evolve
  for(int istep = 0; istep < NSTEPS; ++istep) {
    std::string fname = "post/datos-" + std::to_string(istep) + ".csv";
    std::ofstream fout(fname);
    time_integration(ball, DT);
    compute_force(ball, istep);
    print(ball, istep*DT);
    /*std::cout<< 0.5*ball.mass*(ball.Vx*ball.Vx +
                                                        ball.Vy*ball.Vy +
                                                        ball.Vz*ball.Vz) +
      ball.mass*G*ball.Ry + compute_force(ball, istep) << std::endl;
    fout << ball.Rx << ", "
         << ball.Ry << ", "
         << ball.Rz << ", "
         << ball.mass << ", "
         << ball.rad << "\n ";
      fout.close();*/
  }

  return 0;
}
