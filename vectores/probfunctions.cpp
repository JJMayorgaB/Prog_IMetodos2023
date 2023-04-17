#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>

void lim_vector(std::vector<double>& v, double& val_min, double& val_max);
std::vector<double> histograma(std::vector<double>& v, double& val_min, double& val_max, int N);
std::vector<double> pdf(std::vector<double>& v, double& val_min, double& val_max, int N);
std::vector<double> cdf(std::vector<double> pdf, double& val_min, double& val_max, int N);
std::vector<double> x_func(double& val_min, double& val_max, int N);

int main(int argc, char **argv){

    int N = std::atoi(argv[2]);

    std::vector<double> xdata;
    double x;

    std::string fname = argv[1];

    std::ifstream fin (fname); 

    while (fin >> x) { 

	    xdata.push_back(x); 

    }

    fin.close();

    double min, max;
    lim_vector(xdata, min,  max);
    std::vector<double> hist = histograma(xdata, min, max, N); //se pueden añadir las funciones histograma y lim_vector como argumentos mediante templates a las demas funciones pero no pude hacerlo con una funcion que retornaba un vector

    std::vector<double> prob_func = pdf(hist, min, max, N);

    std::vector<double> cum_func = cdf(prob_func, min, max, N);

    std::vector<double> x_val = x_func(min, max, N);

    std::ofstream fout("stats.txt");

    for(int i = 0; i < N; i++){

        fout << x_val[i] << "\t" << prob_func[i] << "\t" << cum_func[i] << "\n";

    }

    fout.close();

    return 0;
}

void lim_vector(std::vector<double>& v, double& val_min, double& val_max) {

    val_min = val_max= v[0];

    for (const auto& x : v) {

        if (x < val_min) {

            val_min = x;

        }
        if (x > val_max) {

            
            val_max = x;
        }

    }
}

std::vector<double> histograma(std::vector<double>& v, double& val_min, double& val_max, int N){

    std::vector<double> hist(N, 0.0);

    double delta_x = (val_max - val_min) / N;;

    for(int i = 0; i < N ; i++){

        for(int j = 0; j < v.size(); j++){

            if(((val_min + (delta_x * i)) <= v[j]) && (v[j] < (val_min + (delta_x * (i + 1))))){

                hist[i]++;

            }            
        }

    }

    return hist;
}

std::vector<double> pdf(std::vector<double>& v, double& val_min, double& val_max, int N){

    std::vector<double> pdf(N, 0.0);

    int data_size = v.size();

    double delta_x = (val_max - val_min) / N;

    for (int i = 0; i < N; i++) {

        pdf[i] = v[i] / (data_size * delta_x);

    }   

return pdf;

}

std::vector<double> cdf(std::vector<double> pdf, double& val_min, double& val_max, int N){

    std::vector<double> cdf(N, 0.0);
    double delta_x = (val_max - val_min) / N;

    cdf[0] = pdf[0] * delta_x;

    for (int i = 1; i < N; i++) {

        cdf[i] = cdf[i-1] + pdf[i] * delta_x;

    }   

    return cdf;

}

std::vector<double> x_func(double& val_min, double& val_max, int N){

    double delta_x = (val_max - val_min) / N;
    std::vector<double> x(N, 0.0);

    for (int i = 0; i < N; i++) {

        x[i] = val_min + (i * delta_x);

    }

    return x;

}