#include<iostream>
#include<chrono>

#include <cuda.h>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/transform.h>
#include <thrust/functional.h>

#include <boost/numeric/odeint.hpp>

//1. Configurar el solver Odeint con CUDA:
typedef thrust::device_vector<double> state_type;
namespace odeint = boost::numeric::odeint;
typedef odeint::runge_kutta4<state_type> stepper_type;


// 2b. Definir el sistema de ecuaciones diferenciales de manera tradicional:
void lorenz( const state_type &x , state_type &dxdt , double t )
{
    dxdt[0] = sigma * ( x[1] - x[0] );
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = -b * x[2] + x[0] * x[1];
}

// 2a. Definimos el sistema paralelizando los calculos en cuda
void lorenz_cuda(const state_type& x, state_type& dxdt, double t)
{
    const size_t N = x.size();

    // Utilizar operaciones vectoriales para cálculos paralelos se define dxdx[0]
    thrust::transform(x.begin(), x.end(), dxdt.begin(),
        [=] __device__ (const value_type& xi) {
            return sigma * (xi - x[0]);
        });

    // Utilizar operaciones vectoriales y paralelización en el cálculo de dxdt[1]
    thrust::transform(thrust::make_counting_iterator<size_t>(0),
        thrust::make_counting_iterator<size_t>(N),
        dxdt.begin() + 1,
        [=] __device__ (size_t i) {
            return R * x[i - 1] - x[i] - x[i - 1] * x[i + 1];
        });

    // Utilizar operaciones vectoriales y paralelización en el cálculo de dxdt[2]
    thrust::transform(thrust::make_counting_iterator<size_t>(0),
        thrust::make_counting_iterator<size_t>(N),
        dxdt.begin() + 2,
        [=] __device__ (size_t i) {
            return -b * x[i + 2] + x[i] * x[i + 1];
        });
}


//3.Definir las condiciones iniciales y el rango de integración:

int main(){

    // Vector de condiciones iniciales
    state_type x0(size_t N);

    // Configurar el rango de integración (por ejemplo, de 0 a 1)
    double t_start = 0.0;
    double t_end = 1.0;
    double dt = 0.01;

    //4.Resolver el sistema de ecuaciones utilizando Odeint y CUDA:

    // Medir el tiempo de ejecución de lorenz
    auto start = std::chrono::high_resolution_clock::now();
    odeint::integrate_const(stepper_type(), lorenz, x0, t_start, t_end, dt);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Medir el tiempo de ejecución de lorenz_cuda
    auto start_cuda = std::chrono::high_resolution_clock::now();
    odeint::integrate_const(stepper_type(), lorenz_cuda, x0, t_start, t_end, dt);
    auto end_cuda = std::chrono::high_resolution_clock::now();
    auto duration_cuda = std::chrono::duration_cast<std::chrono::microseconds>(end_cuda - start_cuda);

    // Imprimir los tiempos de ejecución
    std::cout << "Tiempo de ejecución de lorenz_cuda: " << duration_cuda.count() << " microsegundos" << std::endl;
    std::cout << "Tiempo de ejecución de lorenz: " << duration.count() << " microsegundos" << std::endl;

    return 0;

}