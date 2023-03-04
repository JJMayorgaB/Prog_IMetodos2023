#include <iostream>
#include <cmath>
#include <fstream>

bool compruebaprimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::pair<int, int> twinprimes(int n) {
    int i = 0;
    int j = 3;
    while (true) {
        if (compruebaprimo(j) && compruebaprimo(j + 2)) {
            i++;
            if (i == n) {
                return std::make_pair(j, j + 2);
            }
        }
        j++;
    }
}

double norma(int x){

    std::pair<int, int> result = twinprimes(x); 
    int a = result.first;
    int b = result.second;
    int c = std::pow(a,2);
    int d = std::pow(b,2);

    return(std::sqrt( c + d ));

}

int main(void)
{

    std::ofstream fout("norma.txt");
    int x = 0;

    for (x = 0; x <= 101; x=x+10) {

        fout << x << "\t" << norma(x) << "\n";

     }
    fout.close();

     return 0;
}