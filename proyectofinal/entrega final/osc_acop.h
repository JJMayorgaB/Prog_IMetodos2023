#pragma once

#include <boost/numeric/odeint.hpp>
#include <random>
#include <vector>

// Define the type for the state vector
typedef std::vector<double> state_type;

void coupled_oscillator(const state_type& x, state_type& dxdt, const double &k, const double &m, const double &friction_coefficient);
void integration_energy(const double &initial_energy, state_type &init_cond, double &dt, const double m, const double k, const double cf);
double total_menergy(const state_type& x, const double &k, const double &m );
state_type uniform_initcond(const int &M, const double &x0, const double &v0);
state_type random_initcond(const int &M, const int &semilla);
state_type inv_initcond(const int &M, const double &x0, const double &v0);
