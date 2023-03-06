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

int main(){


    double x = 3141.5926;

    std::ofstream fout("datos.txt");

    for(int n = 1; n <= 20; n++) {

        double r = sqrt_heron(x, n);

        fout << n << "\t" << std::fabs(1 - r/std::sqrt(x)) << std::endl;

    }

    fout.close();

    return 0;
}

