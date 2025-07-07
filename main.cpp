#include <iostream>
#include <vector>
#include <random>
#include <fstream>

#include "./graph.hpp"

int main(){
    int N = 10000;
    int rep = 10;
    int step = 15;
    int tmax = 15000;
    LinkedGraph graph(N);
    
    std::ofstream ERfile("./data/ER.txt");
    std::ofstream ProductRuleFile("./data/PR.txt");
    std::ofstream SumRuleFile("./data/SR.txt");
    std::ofstream BFfile("./data/BF.txt");

    std::ofstream ERsecondFile("./data/ERsecond.txt");
    std::ofstream ProductRulesecondFile("./data/PRsecond.txt");
    std::ofstream SumRulesecondFile("./data/SRsecond.txt");
    std::ofstream BFsecondFile("./data/BFsecond.txt");
    
    double ERvector [tmax/step] = {0}; 
    double ERsecond [tmax/step] = {0};
    for (int r = 0; r < rep; r++) {
        LinkedGraph graph(N); // Create a graph with 10 nodes
        for(int i = 0; i < tmax; i+= step) {
            graph.addRandomEdges(step); // Add a random edge
            ERvector[int(i/step)] += ((graph.getLCC()/double(N))) / double(rep); // Get the LCC size
            ERsecond[int(i/step)] += ((graph.getSecondLargestClusterSize()/double(N))) / double(rep); // Get the second cluster size
        }
    }
   

    // start again with a new graph
    double PRvector [tmax/step] = {0}; 
    double PRsecond[tmax/step] = {0};
    for (int r = 0; r < rep; r++) {
        graph = LinkedGraph(N);
        for(int i = 0; i < tmax; i+= step) {
            graph.addRandomEdgesProductRule(step); // Add a random edge
            PRvector[int(i/step)] += ((graph.getLCC()/double(N))) / double(rep); // Get the LCC size
            PRsecond[int(i/step)] += ((graph.getSecondLargestClusterSize()/double(N))) / double(rep); // Get the second cluster size
        }
    }

    // start again with a new graph
    double SRvector [tmax/step] = {0}; 
    double SRsecond[tmax/step] = {0};
    for (int r = 0; r < rep; r++) {
        graph = LinkedGraph(N);
        for(int i = 0; i < tmax; i+= step) {
            graph.addRandomEdgesSumRule(step); // Add a random edge
            SRvector[int(i/step)] += ((graph.getLCC()/double(N))) / double(rep); // Get the LCC size
            SRsecond[int(i/step)] += ((graph.getSecondLargestClusterSize()/double(N))) / double(rep); // Get the second cluster size
        }
    }

    // start again with a new graph
    double BFvector [tmax/step] = {0}; 
    double BFsecond[tmax/step] = {0};
    for (int r = 0; r < rep; r++) {
        graph = LinkedGraph(N);
        for(int i = 0; i < tmax; i+= step) {
            graph.addEdgesBFRule(step); // Add a random edge
            BFvector[int(i/step)] += ((graph.getLCC()/double(N))) / double(rep); // Get the LCC size
            BFsecond[int(i/step)] += ((graph.getSecondLargestClusterSize()/double(N))) / double(rep); // Get the second cluster size
        }
    }

    // Write the results to the files
    for (int i = 0; i < tmax/step; i++) {
        ERfile << step*i << " " << ERvector[i] << std::endl;
        ProductRuleFile << i*step << " " << PRvector[i] << std::endl;
        SumRuleFile << step*i << " " << SRvector[i] << std::endl;
        BFfile << i*step << " " << BFvector[i] << std::endl;
        // Write the second cluster sizes
        ERsecondFile << step*i << " " << ERsecond[int(i)] << std::endl;
        ProductRulesecondFile << step*i << " " << PRsecond[int(i)] << std::endl;
        SumRulesecondFile << step*i << " " << SRsecond[i] << std::endl;
        BFsecondFile << i*step << " " << BFsecond[(i)] << std::endl;
    }
}