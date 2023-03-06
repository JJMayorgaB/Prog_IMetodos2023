#include <iostream>

int main(){

    int bound;
    std::cout << "enter a positive integer: ";
    std::cin >> bound;
    double sum = 0.0;
    int i = 1;
    while (i <= bound){
        sum = sum + (1.0/i);
        i += 1;
    }
    std::cout << sum << "\n";
    return 0;
}