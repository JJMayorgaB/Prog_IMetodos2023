#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <chrono>
#include <random>

#include "osc_acop.h"

typedef std::vector<double> state_type;

int main(int argc, char** argv)
{   
    const int M = 3000;  // Final number of masses

    std::ofstream fout("time.txt");

    for (int i = 1; i <= M; i++){

        const double m = M/i;  // Final number of masses
        const double k = 1.0;
        const double cf = 0.5;

        // Define the initial conditions
        state_type cond_ini = random_initcond(M, 12345)
        
        // Define the time separation
        double dt = 0.01;

        state_type dxdt(2 * i);

        double energia_total = total_menergy(cond_ini, k, m); 

         auto start = std::chrono::high_resolution_clock::now();
        // Integrate the coupled oscillator system
        integration_energy(energia_total, cond_ini, dt, m, k, cf);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);


        fout << "Number of masses" << "\t" << i << "\t" << "Time" << "\t" << duration.count() << "\n";

    }

    fout.close();

    return 0;
}

