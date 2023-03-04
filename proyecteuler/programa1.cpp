#include <iostream>
#include <cstring>

bool comprueba_primo(int n){

    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int suma_primos(int n){
    int suma = 0;
    for (int i = 2; i <= n; i++){
        if (comprueba_primo(i)){
            suma += i;
        }
    }
    return suma;
}

int main(int argc, char **argv){

    if (argc < 2){
        std::cout << "Ingrese un numero entero positivo como argumento." << std::endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    if (n <= 0){
        std::cout << "El numero ingresado debe ser un entero positivo." << std::endl;
        return 1;
    }
    std::cout << suma_primos(n) << std::endl;
    return 0;
}

//hola este fue mi primer cambio usando un repositorio de github
