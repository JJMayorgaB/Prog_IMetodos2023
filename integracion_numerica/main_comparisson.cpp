#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "integration.h"

double myfun(double x);

int main(int argc , char **argv)
{
  std::ofstream fout("datos.txt");
  fout.precision(15);
  fout.setf(std::ios::scientific);

  double A = 0.0;
  double B = M_PI;
  double exact = 2.0;

  for(int npoint = 4; npoint <= 600; npoint += 2) {
    double val_simpson = simpson(myfun, A, B, npoint);
    double val_simpson_richardson = richardson(simpson, myfun, A, B, npoint, 4);
    fout << npoint
         << "\t" << std::fabs(1 - val_simpson/exact)
         << "\t" << std::fabs(1 - val_simpson_richardson/exact)
         << "\n";
  }

  fout.close();
  return 0;
}

double myfun(double x)
{
  return std::sin(x);
}

//codigo modularizado con .h es mas corto y facil de leer ademas de ordenado