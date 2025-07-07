#include <iostream>
#include <vector>
#include <random>
#include <fstream>

#include "include/graph.hpp"

int main(){
    int N = 100000;

    int tValues[] = {N/2-40000, N/2-20000, N/2, N/2+20000, N/2 + 40000};

    for(int p : tValues){
        LinkedGraph graph(N); // Create a new graph with N nodes
        graph.addRandomEdges(p);    // insert here the type of percoltion
        std::vector<int> distribution = graph.getClusterDistribution();
        std::string prefix = std::to_string(p);
        std::ofstream file("./data/ClusterDistribution/ER_" + prefix + ".txt");
        for (int i = 0; i < distribution.size(); i++) {
            file << distribution[i] << std::endl;
        }
        file.close();
    }
}