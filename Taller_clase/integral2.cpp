#include <iostream>
#include "mpi.h"

void integral( int ns, int nslocal, int pid, int nproc);

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int pid = 0, nproc = 0;

  const int NS = 6000000;

  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);

  const int NSlocal = NS/nproc;

   double start = MPI_Wtime();
  integral(NS, NSlocal, pid, nproc);
  double end = MPI_Wtime();
  if (0 == pid) {
    std::cout << end-start << "\n";
  }
  
  MPI_Finalize();
  
  return 0;
}

void integral( int ns, int nslocal, int pid, int nproc)
{
    int tag = 0;

    double sum = 0.0;

    double x=0.0, delta = 0.0, inlocal = 0.0;

    delta = 10.0/ns;


    for(int ilocal = 0; ilocal < nslocal; ++ilocal){
        x = (ilocal+pid*nslocal)*delta;
        inlocal += (10.0*x/ns)*(10.0*x/ns)*delta;
    }
    
    if (0 == pid) {
        double aux;
        sum = inlocal;
    for (int src = 1; src < nproc; ++src) {
      MPI_Recv(&aux, 1, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      sum += aux;
    }
    //std::cout.precision(14);
    std::cout << "Resultado:" << sum << "\n";
} else {
    int dest = 0;
    MPI_Send(&sum, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }
}
