#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Dense>
#include <chrono>

double solvesystem(int n);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]); 
    int REPS = std::atoi(argv[2]);

    double t = 0;
    for (int irep = 0; irep < REPS; ++irep) {
        t += solvesystem(N);
    }
    std::cout << t/REPS << std::endl;

    return 0;
}

double solvesystem(int n)
{
   Eigen::MatrixXd A(n, n);
   A = Eigen::MatrixXd::Random(n, n);

   auto start = std::chrono::steady_clock::now();
   //cout << "Here is the matrix A:\n" << A << endl;
   Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(A);
   if (eigensolver.info() != Eigen::Success) abort();
   //cout << "The eigenvalues of A are:\n" << eigensolver.eigenvalues() << endl;
   //cout << "Here's a matrix whose columns are eigenvectors of A \n"
   //<< "corresponding to these eigenvalues:\n"
   //<< eigensolver.eigenvectors() << endl;
   auto end = std::chrono::steady_clock::now();
   double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;
   
   return time;
}
