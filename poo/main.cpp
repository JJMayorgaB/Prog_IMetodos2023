#include "Particle.h"
#include "integrator.h"
//#include "Simulation.h"
#include <vector>

int main(int argc, char **argv) {
	const int N = 1;
	std::vector<Particle> particles(N);
	TimeIntegrator integrator(0.1);

	// Initialize particles: R(0), V(0)
	init_system(particles);
	// Compute initial forces: F(0)
	compute_forces(particles);

	// start integration
	integrator.startIntegration(particles);

	// print state
	print_state(particles, 0.0);
	// Time loop
	// compute new positions and velocities: integration
	integrator.timeStep(particles);
	// compute new forces: F(t+dt)
	// compute_forces(particles);
	// print state
	// print_state(particles, t+dt);

	return 0;
}