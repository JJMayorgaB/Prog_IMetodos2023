#include <iostream> 
#include <Eigen/Dense>
#include <string>

//Juan Pablo Gonzales
//Sergio Andres Cifuentes Vasquez
//Luis Diego Aunta Molina
//Juan José Mayorga Bonilla
//Juan Camilo Parra Saavedra

using Eigen::MatrixXd;

int main(int argc, char **argv)
{

    int m = std::stoi(argv[1]);

    MatrixXd A = MatrixXd::Random(m,m);
    MatrixXd B = A.inverse();

    MatrixXd C = A*B;

    std::cout << C(0,0) << std::endl;
  
}