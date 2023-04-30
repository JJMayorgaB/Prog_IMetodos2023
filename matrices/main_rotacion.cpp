#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

std::vector<double> matvec(const std::vector<double>& mat, const std::vector<double>& vec, const int M);
std::vector<double> matmul_naive(const std::vector<double> & A, const std::vector<double> & B, const int nrows, const int ncols);
std::vector<double> rotation(std::vector<double> v, std::vector<double> theta);

int main(int argc, char **argv){

    //Control de errores en caso de no brindar suficientes o ningun argumento
    if (argc < 2) {
        std::cerr << "Error. Usage: No Argument Provided\n";
        return 1;
   }

    if (argc != 7) {
        std::cerr << "Error. Usage: Enough Arguments Not Supplied\n"
                  << argv[1] << " vx \n"
                  << argv[2] << " vy \n"
                  << argv[3] << " vz \n"
                  << argv[4] << " thetax \n"
                  << argv[5] << " thetay \n"
                  << argv[6] << " thetaz \n";
        return 1;
    }

    //Se declaran los valores de nuestro vector y los angulos de rotacion
    double vx = std::stod(argv[1]);
    double vy = std::stod(argv[2]);
    double vz = std::stod(argv[3]);
    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    //Inicializar el vector a rotar y los angulos que rota
    std::vector<double> v = {vx, vy, vz};
    std::vector<double> theta = {thetax, thetay, thetaz};

    //Se usa la función rotacion para obtener el vector rotado
    std::vector<double> v_rot = rotation(v,theta);

    //Se imprime el vector
    std::cout << v_rot[0] << " " << v_rot[1] << " " << v_rot[2] << std::endl;

    return 0;
}

// Función para rotar un vector en R^3
std::vector<double> rotation(std::vector<double> v, std::vector<double> theta){

    std::vector<double> Rx(9);
    Rx[0] = 1.0;
    Rx[1] = 0.0;
    Rx[2] = 0.0;
    Rx[3] = 0.0;
    Rx[4] = std::cos(theta[0]);
    Rx[5] = (-1.0)*std::sin(theta[0]);
    Rx[6] = 0.0;
    Rx[7] = std::sin(theta[0]);
    Rx[8] = std::cos(theta[0]);

    
    std::vector<double> Ry(9);
    Ry[0] = std::cos(theta[1]);
    Ry[1] = 0.0;
    Ry[2] = std::sin(theta[1]);
    Ry[3] = 0.0;
    Ry[4] = 1.0;
    Ry[5] = 0.0;
    Ry[6] = (-1.0)*std::sin(theta[1]);
    Ry[7] = 0.0;
    Ry[8] = std::cos(theta[1]);


    std::vector<double> Rz(9);
    Rz[0] = std::cos(theta[2]);
    Rz[1] = (-1.0)*std::sin(theta[2]);
    Rz[2] = 0.0;
    Rz[3] = std::sin(theta[2]);
    Rz[4] = std::cos(theta[2]);
    Rz[5] = 0.0;
    Rz[6] = 0.0;
    Rz[7] = 0.0;
    Rz[8] = 1.0;

    std::vector<double> rot_total(9);

    rot_total = matmul_naive(Rz,(matmul_naive(Ry,Rx,3,3)),3,3);
    
    std::vector<double> result(3);

    result = matvec(rot_total,v,3);

    return result;

}

//Función para multiplicar dos matrices cuadradas, devuelve el producto de estas
std::vector<double> matmul_naive(const std::vector<double> & A, const std::vector<double> & B, const int nrows, const int ncols) {
    
    int M = nrows*nrows;

    std::vector<double> result(M);

    for (int ii = 0; ii < nrows; ++ii){
        for (int jj = 0; jj < nrows; ++jj) {
            result[ii*nrows + jj] = 0;
            for (int kk = 0; kk < ncols; ++kk) {
                result[ii*nrows + jj] += A[ii*ncols + kk] * B[kk*nrows + jj];
            }
        }
    }

    return result;
}

//Función para multiplicar una matriz mxm por un vector de tamaño m, devuelve un vector de tamaño m
std::vector<double> matvec(const std::vector<double>& mat, const std::vector<double>& vec, const int M) {
    std::vector<double> result(M, 0.0);
    for (int i=0; i<M; ++i) {
        for (int j=0; j<M; ++j) {
            result[i] += mat[i*M+j] * vec[j];
        }
    }
    return result;
}

