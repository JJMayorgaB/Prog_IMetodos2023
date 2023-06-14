#include <iostream>
#include <vector>
#include <boost/numeric/odeint.hpp>

// Define the type for the state vector
typedef std::vector<double> state_type;

// Define the coupled oscillator system with friction
void coupled_oscillator(const state_type& x, state_type& dxdt, const double /* t */)
{
    const double k = 1.0;  // Spring constant
    const double m = 10.0;  // Mass
    const double friction_coefficient = 0.5;  // Friction coefficient
    double Eks = 0.0;
    double Eus = 0.0;

    // Compute the derivatives for each mass
    for (size_t i = 0; i < dxdt.size(); i += 2)
    {
        dxdt[i] = x[i + 1];
        dxdt[i + 1] = -(k / m) * x[i] - (friction_coefficient / m) * x[i + 1];

        double Ek0 = 0.5 * m * x[i + 1] * x[i + 1];
        double Eu0 = 0.5 * k * x[i] * x[i];

        Eks += Ek0;
        Eus += Eu0;
    }

    double EMT = Eks + Eus;

    std::cout << EMT << "\n";
}

int main()
{
    const size_t M = 10;  // Number of masses

    // Define the initial conditions
    state_type x(2 * M);
    for (size_t i = 0; i < M; ++i)
    {
        x[2 * i] = 0.0;  // Initial position for mass i
        x[2 * i + 1] = 10.0;  // Initial velocity for mass i
    }

    // Define the time span
    double t_start = 0.0;
    double t_end = 500.0;
    double dt = 0.01;

    // Integrate the coupled oscillator system
    boost::numeric::odeint::integrate(coupled_oscillator, x, t_start, t_end, dt);

    // Print the results
    for (size_t i = 0; i < M; ++i)
    {
        std::cout << "Mass " << i + 1 << ":\n";
        std::cout << "Position: " << x[2 * i] << std::endl;
        std::cout << "Velocity: " << x[2 * i + 1] << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
