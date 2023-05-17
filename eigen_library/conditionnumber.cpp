#include <iostream>
#include <cstdlib>
#include <Eigen/Dense>
#include <vector>
#include <cmath>

// Paez Borda, Sebastian
// Mayorga Bonilla, Juan José
// Andrés Felipe Quintero Naranjo
// Carlos Adrián Nieto Melo
// Juan Pablo Gonzalez Rodriguez
// Sergio Andres Cifuentes Vasquez

double condition_number(Eigen::MatrixXd &A);
void initialize_vandermonde(Eigen::MatrixXd &A, int N);

int main(int argc, char **argv) {

  // read size
    const int N = std::stoi(argv[1]);

  // Create matrix
    Eigen::MatrixXd M(N, N); 
    
  // initialize matrix
  initialize_vandermonde(M, N);

  // compute condition number
  double kappa = condition_number(M);

  // print
  std::cout << "kappa = " << kappa << "\n";
  
  return 0;
}

double condition_number(Eigen::MatrixXd &A){

    Eigen::MatrixXd B = A.inverse();

    double detA = A.determinant();
    double detB = B.determinant();

    double k = detA*detB;

    return k;

}

void initialize_vandermonde(Eigen::MatrixXd &A, int N){

    Eigen::VectorXd v(N);

    for (int i = 0; i < N ; i++){

        v[i] = (1.0*(i+1.0))/N;

    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        {
           A(i,j) = std::pow(v[i],j);
        }
    
    }


}