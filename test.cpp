#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "./include/graph.hpp"

std::vector<int> generatePowerLawDegrees(int N, double alpha, int kmin, int kmax) {
    std::vector<double> cdf;
    double norm = 0.0;

    // Costruisci la CDF discreta (non normalizzata)
    for (int k = kmin; k <= kmax; ++k) {
        norm += std::pow(k, -alpha);
        cdf.push_back(norm);
    }

    // Normalizza la CDF
    for (double& val : cdf) val /= norm;

    // Setup RNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Estrai N campioni secondo la distribuzione
    std::vector<int> degrees;
    degrees.reserve(N);

    for (int i = 0; i < N; ++i) {
        double r = dis(gen);
        auto it = std::lower_bound(cdf.begin(), cdf.end(), r);
        int k = std::distance(cdf.begin(), it) + kmin;
        degrees.push_back(k);
    }

    return degrees;
}


std::vector<int> generateStubs(const std::vector<int>& degrees) {
    std::vector<int> stubs;
    for (int i = 0; i < degrees.size(); ++i) {
        stubs.insert(stubs.end(), degrees[i], i); 
    }
    std::cout << "Generated " << stubs.size() << " stubs." << std::endl;
    std::cout << double(stubs.size()) / double(degrees.size()) << " stubs per node on average." << std::endl;
    return stubs;
}

double kappa_scale_free(double gamma, int kmin, int kmax) {
    double numerator = 0.0;
    double denominator = 0.0;
    for (int k = kmin; k <= kmax; ++k) {
        numerator += std::pow(k, 2 - gamma);
        denominator += std::pow(k, 1 - gamma);
    }
    return numerator / denominator;
}

int main(){
    int N = 2*1e5; // Number of nodes
    double alpha = 2.2; // Power-law exponent
    int kmin = 2; // Minimum degree
    int kmax = static_cast<int>(std::pow(N, 1.0 / (alpha - 1)));
    std::vector<int> degrees = generatePowerLawDegrees(N, alpha, kmin, kmax);
    std::vector<int> stubs = generateStubs(degrees);

    std::cout << "kappa = " << kappa_scale_free(alpha, kmin, kmax) << std::endl;

    double avgDeg = double(stubs.size()) / double(N);
    
    std::ofstream file("./data/LCC/PRSF_gamma2.2_kmin2.txt");

    int mMax = avgDeg*N/2; // Maximum number of edges to be added

    LinkedGraph graph(N); // Create a graph with N nodes

    for(int i = 0; i < mMax; i += 5) {
        graph.addEdgesSFPR(5, stubs);
        double lcc = (double)graph.getLCC();
        file << double(i)/double(mMax) << " " << lcc/double(N) << std::endl;
    }
}
