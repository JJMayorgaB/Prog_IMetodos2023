#include<iostream>
#include<valarray>
#include<cmath>

int main()
{
	std::valarray<int> v = {1,2,3,4,5,6,7,8,9,10};

    double suma = v.sum();
    v[v%2 == 0] *= 3;
    v[v%2 != 0] *= 2;

    std::cout << v[0] << " " << v[1] << "\n";
    //v.apply([](int n){std::cout << n << " "; });
    //std::cout << "\n";
  	std::cout << suma << "\n";

  	return 0;
}