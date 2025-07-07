#include <iostream>
#include <vector>
#include <random>
#include <fstream>

#include "./graph.hpp"

int main(){
    int N = 10000;

    int pValues[] = {N/10, N/5, N/3, N/2, N, 2*N};

    for(int p : pValues){
        LinkedGraph graph(N); // Create a new graph with N nodes
        graph.addRandomEdges(p); //critical point
        std::vector<int> distribution = graph.getClusterDistribution();
        std::string prefix = std::to_string(p);
        std::ofstream file("./data/ClusterDistribution/ER_" + prefix + ".txt");
        for (int i = 0; i < distribution.size(); i++) {
            file << distribution[i] << std::endl;
        }
        file.close();
    }
    
    
   


}