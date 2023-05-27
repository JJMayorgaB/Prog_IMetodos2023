#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<random>
#include<string>
#include <fstream>

void init_plate(std::vector<double>& A, int semilla);
void average_temp_per_row(std::vector<double>& A, int rows, int cols, std::vector<double>& average_per_col);

int main(int argc, char **argv){

    const int nrows = std::stoi(argv[1]);
    const int ncol = std::stoi(argv[2]);
    const int seed = std::stoi(argv[3]);

    std::vector<double> m(nrows*ncol);
    std::vector<double> average_per_col(ncol);

    init_plate(m, seed);
    average_temp_per_row(m, nrows, ncol, average_per_col);

    for (int icol = 0; icol < ncol; icol++){

        std::cout << average_per_col[icol] << " ";

    }

    return 0;

}


void init_plate(std::vector<double>& A, int semilla){
    
    std::mt19937 rango(semilla);
    std::uniform_real_distribution<double> dist_uniforme(1.5, 5.5);

    for (int ii = 0; ii < A.size(); ++ii) {

        A[ii] = dist_uniforme(rango);

    }

}


void average_temp_per_row(std::vector<double>& A, int rows, int cols, std::vector<double>& average_per_col){

    for (int ii = 0; ii < cols; ii++) {

        double sum = 0.0;

        for (int jj = 0; jj < rows; jj++) {

            sum += A[jj * cols + ii];

        }

        average_per_col[ii] = sum / rows;

    }


}