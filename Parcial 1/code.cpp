#include <iostream>
#include <cmath>
#include <fstream>

double sqrt_heron(double x, int n){

// La función nos retorna la raiz cuadrada de x despues de hacer n iteraciones con la aproximación de heron

    double r = 1;

    for (int i = 1; i <= n; i++) {
        r = (r + x/r) / 2;
    }
    return r;

}


