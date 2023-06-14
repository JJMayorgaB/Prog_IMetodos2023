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
state_type uniform_initcond(const size_t &M, const double &x0, const double &v0);
state_type random_initcond(const size_t &M, const int &semilla);
void integration_energy(const double &initial_energy, state_type init_cond, double &dt);

int main(int argc, char** argv)
{   
    const size_t M = 100;  // Final number of masses

    for (size_t i = 0; i <= M; i++){

        // Definimos la masa
        state_type m = 100/M;

        // Define the initial conditions
        state_type int_cond = uniform_initcond(M, 0.0, 10.0);
        
        // Define the time separation
        double dt = 0.01;

        state_type dxdt(2 * M);

        coupled_oscillator(int_cond, dxdt, 1.0, m, 0.5); //k=1, mu=0.5

        double energia_total = total_menergy(int_cond, 1.0, m); //k=1

        std::ofstream fout("time.txt");

         auto start = std::chrono::high_resolution_clock::now();
        // Integrate the coupled oscillator system
        integration_energy(energia_total, int_cond, dt);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);


        fout << "Number of masses" << "\t" << M << "\t" << "Time" << duration.count() << "\n";

    }

    return 0;
}

// Define the coupled oscillator system with friction
void coupled_oscillator(const state_type& x, state_type& dxdt, const double &k, const double &m, const double &friction_coefficient)
{
    
    // Compute the derivatives for each mass
    for (size_t i = 0; i < dxdt.size(); i += 2)
    {
        dxdt[i] = x[i + 1];
        dxdt[i + 1] = -(k / m) * x[i] - (friction_coefficient / m) * x[i + 1];
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

state_type uniform_initcond(const size_t &M, const double &x0, const double &v0){
 
    state_type init_conditions(2 * M);

    for (size_t i = 0; i < M; ++i)
    {
        init_conditions[2 * i] = x0;  // Initial position for mass i
        init_conditions[2 * i + 1] = v0;  // Initial velocity for mass i
    }

    return init_conditions;
}

state_type random_initcond(const size_t &M, const int &semilla){

    state_type init_conditions(2 * M);

    std::mt19937 rango(semilla);
    std::uniform_real_distribution<double> dist_uniforme(0, 10);

    for (size_t i = 0; i < M; i++){

        init_conditions[2 * i] = dist_uniforme(rango);  // Initial position for mass i
        init_conditions[2 * i + 1] = dist_uniforme(rango);  // Initial velocity for mass i

    }

    return init_conditions;

}

void integration_energy(const double &initial_energy, state_type init_cond, double &dt){

    double target_energy = initial_energy / 50.0;  // Establecer la energía objetivo

    double current_energy = initial_energy;  // Energía actual del sistema

    while (current_energy > target_energy)
    {   
        double t_start = 0;
        double t_end = t_start + dt;
        boost::numeric::odeint::integrate(coupled_oscillator, init_cond, t_start, t_end, dt);  // Integrar el sistema

        current_energy = total_menergy(int_cond, 1.0, 1.0);  // Calcular la energía actual del sistema
        t_start = t_end;  // Actualizar el tiempo de inicio para la próxima integración
        t_end += dt;  // Incrementar el tiempo final para la próxima integración
    }

}   