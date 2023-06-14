#include "Particle.h"

struct Particle {
	std::valarray<double> R_(3), V_(3), F_(3);
	double mass_, radius_;
};