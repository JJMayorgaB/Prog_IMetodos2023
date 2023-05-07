#include <iostream>
#include <cstdlib>
#include <Eigen/Dense>
#include <complex>
#include <vector>
#include <fstream>

std::vector<double> solvesystem(double k, double m1, double m2);

int main(int argc, char **argv) {

    //Control de errores en caso de no brindar suficientes o ningun argumento
    if (argc < 2) {
        std::cerr << "Error. Usage: No Argument Provided\n";
        return 1;
    }

    if (argc != 3) {
        std::cerr << "Error. Usage: Enough Arguments Not Supplied\n"
                  << argv[1] << " k \n"
                  << argv[2] << " m2 \n";
        return 1;
    }

    // Definir las constantes del sistema
    const double k  = std::stod(argv[1]);
    const double m2 = std::stod(argv[2]);

    // Definir los valores de m1 a explorar
    std::vector<double> m1_values = {1, 2, 4, 8, 10, 16, 20, 30, 35, 38, 40, 42, 45, 48, 50, 55, 80, 100, 150, 200, 300, 400, 500, 600, 800};

    std::ofstream fout("stats.txt");

    for(double m1 : m1_values){

        std::vector<double> frec = solvesystem(k, m1, m2); 

        std::cout << m1 << "\t" << frec[0] << "\t" << frec[1] << "\n";

        fout << m1 << "\t" << frec[0] << "\t" << frec[1] << "\n";

    }

    fout.close();

    return 0;
}


std::vector<double> solvesystem(double k, double m1, double m2)
{
     // Se define la matriz del sistema
    Eigen::MatrixXd A(2, 2);
    A << 2*k/m1, -k/m1, -k/m2, 2*k/m2;

    // Se calculan los valores propios
    Eigen::VectorXcd evals = A.eigenvalues();

    // Calculamos las frecuencias
    std::vector<double> frecuencias = {(std::real(evals[0])), (std::real(evals[1]))};

    return frecuencias;
}