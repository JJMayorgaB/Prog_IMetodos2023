#include <iostream>
#include <string>

int s_impares_fib(int n){

    int a = 1, b = 2, c = 3, k = 0;

    while (a <= n){

        if (a%2 != 0){

            k += a;
        }

        a = b;
        b = c;
        c = a + b;
    }

    return k;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cout << "Debe ingresar un numero entero como argumento" << std::endl;
        return 1;
    }

    int x = std::stoi(argv[1]);

    std::cout << s_impares_fib(x) << std::endl;

    return 0;
}