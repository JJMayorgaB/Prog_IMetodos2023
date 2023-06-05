#include <iostream>
#include <valarray>
#include <cmath>
#include <string>
#include <fstream>

typedef std::valarray<double> state_t;
template <class state_t>

void integrate_euler(state_t & s, double ta, double tb, double dt, double omega);
void heun(state_t& s, double t0, double tf, double delta_t, double omega);

int main(int argc, char** argv) {

    //Control de errores en caso de no brindar suficientes o ningun argumento
    if (argc < 2) {
        std::cerr << "Error. Usage: No Argument Provided\n";
        return 1;
   }

    if (argc != 5) {
        std::cerr << "Error. Usage: Enough Arguments Not Supplied\n"
                  << argv[1] << " delta_t \n"
                  << argv[2] << " to \n"
                  << argv[3] << " tf \n"
                  << argv[4] << " omega \n";
        return 1;
    }

    double delta_t = std::stod(argv[1]);
    double t0 = std::stod(argv[2]);
    double tf = std::stod(argv[3]);  
    double omega = std::stod(argv[4]);

    state_t sh(2);

    sh[0] = 0.2347;
    sh[1] = 0.0;

    state_t se(2);

    se[0] = 0.2347;
    se[1] = 0.0;

    heun(sh, t0, tf, delta_t, omega);

    integrate_euler(se, t0, tf, delta_t, omega);

    return 0;
}

template <class state_t>

void integrate_euler(state_t & s, double ta, double tb, double dt, double omega){

    const int NSTEPS = std::lrint((tb-ta)/dt);

    state_t dsdt(s.size());

    std::ofstream fout("euler_solution.txt");

    for (int tstep = 1; tstep < NSTEPS; tstep++) {

        double time = ta + tstep*dt;

        auto deriv = [s, omega](state_t &dsdt){
                dsdt[0] = s[1];
                dsdt[1] = -(omega*omega)*s[0];
        };

        deriv(dsdt);

        s = s + dt*dsdt;

        fout << time << "\t" << s[0] << "\t" << s[1] << "\n";

    }

    fout.close();

}

void heun(state_t& s, double t0, double tf, double delta_t, double omega){

    std::ofstream fout("heun_solution.txt");

    for (double t = t0; t <= tf; t += delta_t) {

        fout << t << "\t" << s[0] << "\t" << s[1] << "\n";

        state_t k1(2), k2(2);

        auto fderiv = [s, omega](state_t &dsdt){

                dsdt[0] = s[1];
                dsdt[1] = -(omega*omega)*s[0];

        };

        state_t s_temp = s + delta_t * k1;

        fderiv(k1);
        fderiv(k2);

        s += 0.5 * delta_t * (k1 + k2);
    }

    fout.close();

}