#include <iostream>

int main(void) {

    int n;

    std::cout << "Introduce un numero entero: ";
    std::cin >> n;

    if (n%2 == 0 && n!=2){
        std::cout << n << " no es numero no es primo";
    } else {

        bool primo;
        
        for (int i=3; i<=n/2; i=i+2) {
            
            if (n%i==0) {

                primo = false;
                break;
        }
    }

    if (primo && n > 1) {
        std::cout << n << " es un numero primo." << "/n";
    } else {
        std::cout << n << " no es un numero primo" << "\n";
    }}

    return 0;
}