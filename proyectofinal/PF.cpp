#include <iostream>
#include <vector>
#include <valarray>
#include <boost/numeric/odeint.hpp>

// Define the type for the state vector
typedef std::valarray<double> state_type;

void coupled_oscillator(const state_type& x, state_type& dxdt, const double &k, const double &m, const double &friction_coefficient);
double total_menergy(const state_type& x, const double &k, const double &m );
state_type uniform_initcond(const size_t &M, const double &x0 const double &v0);
state_type random_initcond(const size_t &M, const int &semilla);

int main()
{
    const size_t M = 10;  // Number of masses

    // Define the initial conditions
    state_type int_cond = uniform_initcond(M, 0.0, 10.0);

    // Define the time span
    double t_start = 0.0;
    double t_end = 500.0;
    double dt = 0.01;

    // Integrate the coupled oscillator system
    boost::numeric::odeint::integrate(coupled_oscillator, int_cond, t_start, t_end, dt);

    // Print the results
    for (size_t i = 0; i < M; ++i)
    {
        std::cout << "Mass " << i + 1 << ":\n";
        std::cout << "Position: " << int_cond[2 * i] << std::endl;
        std::cout << "Velocity: " << int_cond[2 * i + 1] << std::endl;
        std::cout << std::endl;
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