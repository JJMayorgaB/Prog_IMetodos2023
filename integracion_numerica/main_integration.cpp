#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "integration.h"

double myfun(double x);

int main(int argc , char **argv)
{
  const int NPOINT = std::stoi(argv[1]);
  std::cout.precision(15); std::cout.setf(std::ios::scientific);

  // test with Simpson
  std::cout << "Simpson integral (npoint = " << NPOINT << ") is : "
            << simpson(myfun, 0, M_PI, NPOINT) << std::endl;

  return 0;
}

double myfun(double x)
{
  return std::sin(x);
}

//este algoritmo obtiene la integral de sin(x) mediante el metodo de simpson