#include<iostream>
#include<cmath>
#include<vector>
#include<random>

void init_plate(std::vector<double> M, int seed);
void average_temp_per_row(std::vector<double> M, int rows, int cols, std::vector<double> average_per_col);

int main(){

    const int nrows = 10;
    const int ncol = 10;
    const int seed = 0;

    std::vector<double> m(nrows*ncol);
    std::vector<double> average_per_col(ncol);

    init_plate(m, seed);
    average_temp_per_row(m, nrows, ncol, average_per_col);

    for (int icol = 0; icol < ncol; icol++){

        std::cout << average_per_col[icol] << " ";

    }

    return 0;

}


void init_plate(std::vector<double> M, int seed){
    
    std::mt19937 rng(seed);
    std::uniform_real_distribution<double> dist(1.5, 5.5);

    for (int i = 0; i < M.size(); ++i) {

        M[i] = dist(rng);

    }

}


void average_temp_per_row(std::vector<double> M, int rows, int cols, std::vector<double> average_per_col){

    for (int icol = 0; icol < cols; icol++) {

        double sum = 0.0;

        for (int irow = 0; irow < rows; irow++) {

            sum += M[irow * cols + icol];

        }

        average_per_col[icol] = sum / rows;
        
    }


}