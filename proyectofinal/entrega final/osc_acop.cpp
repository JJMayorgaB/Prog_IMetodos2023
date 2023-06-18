#include "osc_acop.h"

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
        
        auto coupled_oscillator_func = [&](const state_type& x, state_type& dxdt, double t) {
        coupled_oscillator(x, dxdt, k, m, cf);
        };

        boost::numeric::odeint::integrate(coupled_oscillator_func, init_cond, t_start, t_end, dt);  // Integrar el sistema

        current_energy = total_menergy(init_cond, k, m);  // Calcular la energía actual del sistema
        t_start = t_end;  // Actualizar el tiempo de inicio para la próxima integración
        t_end += dt;  // Incrementar el tiempo final para la próxima integración
    }

}   

state_type inv_initcond(const int &M, const double &x0, const double &v0){
 
    state_type init_conditions(2 * M);

    for (int i = 0; i < M; ++i)
    {
        init_conditions[2 * i] = std::pow(-1,i)*x0;  // Initial position for mass i
        init_conditions[2 * i + 1] = std::pow(-1,i+1)*v0;  // Initial velocity for mass i
    }

    return init_conditions;
}