#include<iostream>
#include<cmath>
#include<fstream>

template <typename func_t>
double newton(double x0, double eps, func_t func, int nmax, int & nsteps);

int main(int argc, char **argv){

    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);

    double precision = std::stod(argv[1]); //pedimos la precision para el metodo de newton desde consola se espera que sea 1.0e-15

    std::ofstream fout("datos.txt");

    for(double D=0.001; D<=0.031; D+=0.001){

        int max{100}, min{0};
        //se establece el numero de iteraciones del metodo de newton en 100
        auto freynolds = [](double x){return (1.23*45*x)/1.79e-5;} ; 
        // funcion lambda para el numero de reynolds
        double reynolds = freynolds(D);

        double f0 = 0.316/(std::pow(reynolds,0.25)); //formula de Blasius

        auto colebrook = [D, reynolds](double f){return (2.0*log10((1.4e-6/(3.7*D))+(2.51/(reynolds*std::sqrt(f)))))+(1.0/std::sqrt(f));};
        //Funcion lambda para la ecuacion de Colebrook 

        double N = newton(f0, precision, colebrook, max, min);
        // Se calcula la fricción con el metodo de newton 

        auto presion = [N,D](){return(N*((0.2*1.23*2025)/(2*D)));};
        double result = presion();

        fout.precision(15);
        fout << std::scientific;
        fout << D << "\t" << result << "\n";
        //Se guardan en un archivo .txt la friccion y el diametro 
        //para cada uno de los diametros de la tuberia D entre 0.001 y 0.031 metros.
    }

    fout.close();
}

//funcion para el metodo de newton-raphson
template <typename func_t>
double newton(double x0, double eps, func_t func, int nmax, int & nsteps){
  nsteps = 0;
  double xr = x0;
  while(nsteps <= nmax) {
    if (std::fabs(func(xr)) < eps) {
      break;
    }
    else {
      double h = 0.001;
      double deriv = (func(xr+h/2) - func(xr-h/2))/h;
      xr = xr - (func(xr)/deriv);
    }
    nsteps++;
  }
  return xr;
}




