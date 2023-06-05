#include<iostream>

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


// 2. Definir el sistema de ecuaciones diferenciales:
void lorenz( const state_type &x , state_type &dxdt , double t )
{
    dxdt[0] = sigma * ( x[1] - x[0] );
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = -b * x[2] + x[0] * x[1];
}

//3.Definir las condiciones iniciales y el rango de integración:

// Vector de condiciones iniciales
state_type x0(N);

// Configurar el rango de integración (por ejemplo, de 0 a 1)
double t_start = 0.0;
double t_end = 1.0;
double dt = 0.01;

//4.Resolver el sistema de ecuaciones utilizando Odeint y CUDA:
odeint::integrate_const(stepper_type(), lorenz, x0, t_start, t_end, dt);