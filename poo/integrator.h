#pragma once

//Andres Felipe Gomez Cuesta
// Luis Diego Aunta Molina
// Jairo Enrique Salamanca Parra
// Juan José Mayorga Bonilla

class TimeIntegrator{

  double dt{0.0};

  public:
  TimeIntegrator(double DT) { dt = DT; }

  template <class particle_array_t>
  void startIntegration(particle_array_t & parray) {
     for (auto & p : parray) {
         p.V = p.V - dt*p.F/(2*p.mass);
     }
  }

  template <class particle_array_t>
  void timeStep(particle_array_t & parray) {
    
    for (auto &p : parray){

      p.V = p.V + (dt*p.F/p.mass);
      p.R = p.R + (p.V*dt);

    }

  }

};