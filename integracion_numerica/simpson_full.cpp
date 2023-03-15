#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using fptr=double(double);

double myfun(double x);
double simpson(fptr func, const double a, const double b, const int npoint);

int main(int argc , char **argv)
{
  const int NPOINT = std::stoi(argv[1]);
  std::cout.precision(15); std::cout.setf(std::ios::scientific);

  // test with Simpson
  std::cout << "Simpson integral (npoint = " << NPOINT << ") is : " << simpson(myfun, 0, M_PI, NPOINT) << std::endl;

  return 0;
}

double myfun(double x)
{
  return std::sin(x);
}

double simpson(fptr func, const double a, const double b, const int npoint)
{
  // check for even number of points
  int nlocal = npoint;
  if (nlocal%2 != 0) {
    nlocal += 1;
  }
  double sum = 0, result = func(a) + func(b);
  double x;
  const double h = (b-a)/nlocal;

  // first sum
  sum = 0;
  for(int ii = 1; ii <= nlocal/2 - 1; ++ii ) {
    x = a + 2*ii*h;
    sum += func(x);
  }
  result += 2*sum;

  // second sum
  sum = 0;
  for(int ii = 1; ii <= nlocal/2; ++ii ) {
    x = a + (2*ii-1)*h;
    sum += func(x);
  }
  result += 4*sum;

  return result*h/3;
}

//codigo completo sin modulizar 