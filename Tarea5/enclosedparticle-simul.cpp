#include "enclosedparticle-simul.h"


void initial_conditions(Particle & body)
{
  body.Rx = 1.23698;
  body.Ry = 1.1598;
  body.Rz = 0.9598;
  body.Vx = 3.23698;
  body.Vy = 2.23698;
  body.Vz = 1.45;

  body.rad = 0.235;
  body.mass = 0.29698;
}

double compute_force(Particle & body, double time)
{
  double ElasticPotentialEnergy = 0;
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;

  // gravitational force
  body.Fy += body.mass*G;

  // forces with ground and roof
  double delta = body.rad - body.Ry;

  if (delta > 0) {
    body.Fy += K*delta;
    //body.Fy -= 0.2*body.Vy;
    ElasticPotentialEnergy = -0.5*K*(delta*delta);
  }
  delta = body.Ry + body.rad - LY_f;
  if (delta > 0) {
    body.Fy -= K*delta;
    //body.Fy -= 0.2*body.Vy;
    ElasticPotentialEnergy = -0.5*K*(delta*delta);
  }

  // forces with right wall and left wall
  delta = body.Rx + body.rad - LX_f;
  if (delta > 0) {
    body.Fx -= K*delta;
    //body.Fx -= 0.2*body.Vx;
    ElasticPotentialEnergy = -0.5*K*(delta*delta);
  }
  delta= body.rad - body.Rx;
  if (delta > 0) {
    body.Fx += K*delta;
    //body.Fx -= 0.2*body.Vx;
    ElasticPotentialEnergy = -0.5*K*(delta*delta);
  }
  // forces with front and back walls
  delta = body.Rz + body.rad - LZ_f;
  if (delta > 0) {
    body.Fz -= K*delta;
    //body.Fz -= 0.2*body.Vz;
    ElasticPotentialEnergy = -0.5*K*(delta*delta);
  }
  delta= body.rad - body.Rz;
  if (delta > 0) {
    body.Fz += K*delta;
    //body.Fz -= 0.2*body.Vz;
    ElasticPotentialEnergy = -0.5*K*(delta*delta);
  }

  return ElasticPotentialEnergy;
}

void start_integration(Particle & body, const double & dt)
{
  body.Vx -= body.Fx*dt/(2*body.mass);
  body.Vy -= body.Fy*dt/(2*body.mass);
  body.Vz -= body.Fz*dt/(2*body.mass);
}

  void time_integration(Particle & body, const double & dt)
{
  // leap-frog
  body.Vx += body.Fx*dt/(body.mass);
  body.Vy += body.Fy*dt/(body.mass);
  body.Vz += body.Fz*dt/(body.mass);
  body.Rx += body.Vx*dt;
  body.Ry += body.Vy*dt;
  body.Rz += body.Vz*dt;
}

void print(Particle & body, double time)
{
  std::cout << time << "  "
            << body.Rx << "  "
            << body.Ry << "  "
            << body.Rz << "  "
            << body.Vx << "  "
            << body.Vy << "  "
            << body.Vz << "  "
            << -compute_force(body,time) +0.5*body.mass*(body.Vx*body.Vx +
                                                         body.Vy*body.Vy +
                                                         body.Vz*body.Vz) -
    body.mass*G*body.Ry
            << "\n";
}
