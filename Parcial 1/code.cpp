#include <iostream>
#include <cmath>
#include <fstream>

double sqrt_heron(double x, int n){

// La función nos retorna la raiz cuadrada de x despues de hacer n iteraciones con la aproximación de heron

    double r = 1.0;

    for (int i = 1; i < n; i++) {

        r = 0.5*(r + x/r);

    }
    return r;

}

int main(){

    std::cout.setf(std::ios::scientific);

    double x = 3.1415926;
    double r = sqrt_heron(x, 5);
    std::cout << r << " " << std::fabs(1 - r/std::sqrt(x)) << std::endl;

}

