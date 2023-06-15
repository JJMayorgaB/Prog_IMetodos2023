#include <iostream>
#include <vector>
#include <valarray>
#include <cmath>
#include <string>
#include <fstream>
#include<chrono>

#include <boost/numeric/odeint.hpp>

// Define the type for the state vector
typedef std::valarray<double> state_type;

void coupled_oscillator(const state_type& x, state_type& dxdt, const double &k, const double &m, const double &friction_coefficient);
double total_menergy(const state_type& x, const double &k, const double &m );
state_type uniform_initcond(const int &M, const double &x0, const double &v0);
state_type random_initcond(const int &M, const int &semilla);
void integration_energy(const double &initial_energy, state_type &init_cond, double &dt, const double m, const double k, const double cf);

int main(int argc, char** argv)
{   
    const int M = 100;  // Final number of masses

    for (int i = 0; i < M; i++){

        const double m = 100/M;  // Final number of masses
        const double k = 1.0;
        const double cf = 0.5;

        // Define the initial conditions
        state_type cond_ini = uniform_initcond(M, 0.0, 10.0);
        
        // Define the time separation
        double dt = 0.01;

        state_type dxdt(2 * M);

        double energia_total = total_menergy(cond_ini, k, m); 

        std::ofstream fout("time.txt");

         auto start = std::chrono::high_resolution_clock::now();
        // Integrate the coupled oscillator system
        integration_energy(energia_total, cond_ini, dt, m, k, cf)
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);


        fout << "Number of masses" << "\t" << M << "\t" << "Time" << duration.count() << "\n";

    }

    return 0;
}

// Define the coupled oscillator system with friction
void coupled_oscillator(const state_type& x, state_type& dxdt, const double &k, const double &m, const double &cf)
{
    
    // Compute the derivatives for each mass
    for (size_t i = 0; i < dxdt.size(); i += 2)
    {
        dxdt[i] = x[i + 1];
        dxdt[i + 1] = -(k / m) * x[i] - (cf/m) * x[i + 1];
    }

}

double total_menergy(const state_type& x, const double &k, const double &m ){

    double Eks = 0.0;
    double Eus = 0.0;

    for (size_t i = 0; i < x.size(); i += 2)
    {

        double Ek0 = 0.5 * m * x[i + 1] * x[i + 1];
        double Eu0 = 0.5 * k * x[i] * x[i];

        Eks += Ek0;
        Eus += Eu0;
    }

    double EMT = Eks + Eus;
    
    return EMT;
}

state_type uniform_initcond(const int &M, const double &x0, const double &v0){
 
    state_type init_conditions(2 * M);

    for (int i = 0; i < M; ++i)
    {
        init_conditions[2 * i] = x0;  // Initial position for mass i
        init_conditions[2 * i + 1] = v0;  // Initial velocity for mass i
    }

    return init_conditions;
}

state_type random_initcond(const int &M, const int &semilla){

    state_type init_conditions(2 * M);

    std::mt19937 rango(semilla);
    std::uniform_real_distribution<double> dist_uniforme(0, 10);

    for (size_t i = 0; i < M; i++){

        init_conditions[2 * i] = dist_uniforme(rango);  // Initial position for mass i
        init_conditions[2 * i + 1] = dist_uniforme(rango);  // Initial velocity for mass i

    }

    return init_conditions;

}

void integration_energy(const double &initial_energy, state_type &init_cond, double &dt, const double m, const double k, const double cf){

    double target_energy = initial_energy / 50.0;  // Establecer la energía objetivo

    double current_energy = initial_energy;  // Energía actual del sistema

    double t_start = 0;
    double t_end = t_start + dt;

    while (current_energy > target_energy)
    {   
        
        boost::numeric::odeint::integrate(coupled_oscillator, init_cond, t_start, t_end, dt, k, m, cf);  // Integrar el sistema

        current_energy = total_menergy(int_cond, k, m);  // Calcular la energía actual del sistema
        t_start = t_end;  // Actualizar el tiempo de inicio para la próxima integración
        t_end += dt;  // Incrementar el tiempo final para la próxima integración
    }

}   