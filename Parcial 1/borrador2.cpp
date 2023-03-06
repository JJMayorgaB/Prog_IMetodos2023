#include <iostream>

int main(){

    int x = 15, y = 13;

    if (x >= 0){

        if (y >= 0){

            std::cout << x+y;

        } else {

            std::cout << x-y;

        }
    } else {

        std::cout << y-x;
    }

}