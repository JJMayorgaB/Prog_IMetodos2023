#include <iostream>

bool comprueba_primo(int n){
    if (n <= 1) {
        return false;
    }
    int i;
    for (i=1;(n/2)+1;i++){
        if (n%i == 0){
            return false;
        }
    return true;
    }
}

int sexyprime(int m){
    int k = 0;
    int i = 5;
    while (true){
        if (comprueba_primo(i) && comprueba_primo(i+6)){
            k+=1;
            if(k==m){
                return(i,i+6);
            }
        }
        i+=1;
    }

}