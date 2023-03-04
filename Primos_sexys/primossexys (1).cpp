
#include <iostream>

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

std::pair<int, int> sexyprime(int n) {
    int i = 0;
    int j = 5;
    while (true) {
        if (compruebaprimo(j) && compruebaprimo(j + 6)) {
            i++;
            if (i == n) {
                return std::make_pair(j, j + 6);
            }
        }
        j++;
    }
}

int main() {
    int a = 5 ;{
        std::pair<int, int> result = sexyprime(a);
        std::cout << "(" << result.first << ", " << result.second << ")" << "\n";
    }
    return 0;
}