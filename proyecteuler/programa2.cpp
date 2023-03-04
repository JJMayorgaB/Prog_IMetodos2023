#include <iostream>
#include <string>

long max_factorprimo(long x){
    long f = 2;

    while (f <= x){

        if (x % f == 0 ){
            x /= f;
        } else {
            f+=1;
        }
    }

    return f;
}

int main(int argc, char **argv){

    if (argc < 2){
        std::cout << "Ingrese un numero entero positivo como argumento." << std::endl;
        return 1;
    }
    long n = std::stol(argv[1]);
    if (n <= 0){
        std::cout << "El numero ingresado debe ser un entero positivo." << std::endl;
        return 1;
    }
    std::cout << max_factorprimo(n) << std::endl;
    return 0;
}