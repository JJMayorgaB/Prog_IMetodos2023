#include "integration.h"

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


double richardson(algptr alg, fptr func, const double a, const double b,
                  const int npoint, int order)
{
  double val1 = alg(func, a, b, npoint); // h
  double val2 = alg(func, a, b, npoint/2); // h/2
  double aux = std::pow(2, order);
  return (aux*val2 - val1)/(aux-1);
}

//en este codigo definimos nuestra funcion para la interpolacion de richardson y para el metodo de simpson