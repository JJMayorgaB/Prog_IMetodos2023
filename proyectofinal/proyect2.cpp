#include <iostream>
#include <vector>
#include <valarray>
#include <cmath>
#include <string>
#include <fstream>
#include <chrono>
#include <random>
#include <boost/numeric/odeint.hpp>


// Define the type for the state vector
typedef std::vector<double> state_type;

void coupled_oscillator(const state_type& x, state_type& dxdt, double k, double m, double friction_coefficient);
double total_menergy(const state_type& x, const double &k, const double &m );
state_type uniform_initcond(const double &M, const double &x0, const double &v0);
state_type random_initcond(const double &M, const int &semilla);
void integration_menergy(const double &initial_energy, state_type &init_cond, double &dt, const double m, const double k, const double cf);

int main(int argc, char** argv)
{
    const double M = 100;  // Final number of masses
    const double k = 1.0;
    const double cf = 0.5;

    std::ofstream fout("time.txt");

    for (double i = 1; i <= M; i++){

        // Definimos la masa
        double m = 100.0/i;

        // Define the initial conditions
        state_type int_cond = uniform_initcond(M, 0.0, 10.0);

        // Define the time separation
        double dt = 0.01;

        state_type dxdt(2 * i);

        double energia_total = total_menergy(int_cond, k, m); //k=1

         auto start = std::chrono::high_resolution_clock::now();
        // Integrate the coupled oscillator system
        integration_menergy(energia_total, int_cond, dt, m, k, cf);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);


        fout << "Number of masses" << "\t" << i << "\t" << "Time:" << "\t" << duration.count() << "\n";

    }

    fout.close();

    return 0;
}

// Define the coupled oscillator system with friction
void coupled_oscillator(const state_type& x, state_type& dxdt, double k, double m, double friction_coefficient)
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

state_type uniform_initcond(const double &M, const double &x0, const double &v0){

    state_type init_conditions(2 * M);

    for (size_t i = 0; i < M; ++i)
    {
        init_conditions[2 * i] = x0;  // Initial position for mass i
        init_conditions[2 * i + 1] = v0;  // Initial velocity for mass i
    }

    return init_conditions;
}

state_type random_initcond(const double &M, const int &semilla){

    state_type init_conditions(2 * M);

    std::mt19937 rango(semilla);
    std::uniform_real_distribution<double> dist_uniforme(0, 10);

    for (size_t i = 0; i < M; i++){

        init_conditions[2 * i] = dist_uniforme(rango);  // Initial position for mass i
        init_conditions[2 * i + 1] = dist_uniforme(rango);  // Initial velocity for mass i

    }

    return init_conditions;

}

void integration_menergy(const double &initial_energy, state_type &x, double &dt, const double m, const double k, const double cf){

    double target_energy = initial_energy / 50.0;  // Establecer la energia objetivo

    double current_energy = initial_energy;  // Energia actual del sistema

    double t_start = 0;
    double t_end = t_start + dt;

    while (current_energy > target_energy)
    {

        auto coupled_oscillator_func = [&](const state_type& x, state_type& dxdt, double t) {
        coupled_oscillator(x, dxdt, k, m, cf);
        };

        boost::numeric::odeint::integrate(coupled_oscillator_func, x, t_start, t_end, dt);  // Integrar el sistema

        current_energy = total_menergy(x, k, m);  // Calcular la energia actual del sistema
        t_start = t_end;  // Actualizar el tiempo de inicio para la proxima integracion
        t_end += dt;  // Incrementar el tiempo final para la proxima integracion
    }

}
