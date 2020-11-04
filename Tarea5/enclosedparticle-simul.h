#ifndef __MD_SIMUL_H_
#define __MD_SIMUL_H_

#include <iostream>
#include "particle.h"

const double G = -9.81;
const int NSTEPS = 1000;
const double DT = 0.01;
const double K = 253.57;
const double LX_f = 2.01;
const double LY_f = 2.01;
const double LZ_f = 2.01;

// function declarations
void initial_conditions(Particle & body);
double compute_force(Particle & body, double time);
void time_integration(Particle & body, const double & dt);
void start_integration(Particle & body, const double & dt);
void print(Particle & body, double time);

#endif // __MD_SIMUL_H_
