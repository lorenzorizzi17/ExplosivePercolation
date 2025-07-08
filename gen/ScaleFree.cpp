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


double kappa_from_degree_sequence(const std::vector<int>& degrees) {
    if (degrees.empty()) return 0.0;

    double sum_k = 0.0;
    double sum_k2 = 0.0;

    for (int k : degrees) {
        sum_k += k;
        sum_k2 += static_cast<double>(k) * k;
    }

    return sum_k2 / sum_k;
}

int main(){
    int N = 2*1e5; // Number of nodes
    for(int type = 1; type < 2; type++){  // 0 for RG, 1 for PR
        for (double alpha = 3.5; alpha < 3.6; alpha += 0.4) {
            for (int kmin = 1; kmin < 3; kmin++){

                int kmax = static_cast<int>(std::pow(N, 1.0 / (alpha - 1)));
                std::vector<int> degrees = generatePowerLawDegrees(N, alpha, kmin, kmax);
                std::vector<int> stubs = generateStubs(degrees);

                std::cout << "kappa from degree sequence = " << kappa_from_degree_sequence(degrees) << std::endl;

                double avgDeg = double(stubs.size()) / double(N);
                std::string tp;
                if (type == 0) {
                    tp = "RG";
                } else {
                    tp = "PR";
                }

                std::string filename = "../data/LCC/"+ tp +"SF_gamma" + std::to_string(alpha) + "_kmin" + std::to_string(kmin) + ".txt";
                std::ofstream file(filename);

                int mMax = avgDeg*N/2; // Maximum number of edges to be added (fulling the stubs)

                LinkedGraph graph(N); // Create an empty graph with N nodes
                for(int i = 0; i < mMax; i += 1) {
                    if(type == 0) {
                        graph.addEdgesSF(1,stubs);
                    } else {
                        graph.addEdgesSFPR(1,stubs);
                    }
                    double lcc = (double)graph.getLCC();
                    file << double(i)/double(mMax) << " " << lcc/double(N) << std::endl;
                }

            }
        }
    }
}
