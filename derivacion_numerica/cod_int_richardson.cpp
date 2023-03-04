#include <fstream>
#include <cmath>
#include<iostream>

using fptr = double(double, double);

double f(double x);
double deriv_forward(double x, double h);
double deriv_central(double x, double h);
double richardson(double x, double h, fptr fun);

int main(int argc, char **argv) {

    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);

  const double x = M_PI/3.0;
  const double exact = std::cos(x);

  std::ofstream fout("datos.txt");

  for(int p = -1; p >= -18; p--) {

    double h = std::pow(10.0, p);
    double forward = deriv_forward(x, h);
    double forward_richardson = richardson(x,h, deriv_forward);
    double central = deriv_central(x, h);
    double central_richardson = richardson(x,h, deriv_central);

    fout << h

         << "\t" << std::fabs(1.0 - forward/exact)
         << "\t" << std::fabs(1.0 - central/exact)
         << "\t" << std::fabs(1.0 - forward_richardson/exact)
         << "\t" << std::fabs(1.0 - central_richardson/exact)
         << "\n";
  }
  fout.close();

  return 0;
}

double f(double x)
{
  return std::sin(x);
}

double deriv_forward(double x, double h)
{
  return (f(x+h) - f(x))/h;
}

double deriv_central(double x, double h)
{
  return (f(x+h/2) - f(x-h/2))/h;
}

double richardson(double x, double h, fptr fun)
{
       
    if (fun == deriv_forward){
        return (2*fun(x,h/2)-fun(x, h));
    } else {
        return ((4*fun(x,h/2)-fun(x, h))/3);
    }

}