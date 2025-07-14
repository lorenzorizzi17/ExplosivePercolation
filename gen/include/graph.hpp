#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <algorithm> 

struct Node {
    Node* next = NULL; // Pointer to the next node in the graph. If null, then root node
    std::vector<Node*> neighbors; // A vector of neighbors (adjacency list)
    int ClusterSize = 1;  // If root, store the size of the cluster. Default to 0.
    Node() = default; // Default constructor
};

class LinkedGraph{
    private:
    int N; // Number of nodes
    std::vector<Node> nodes;   // A vector of nodes
    std::mt19937 m_gen; // Random generator

    public:
    // Void constructor (no edges, every node is a root node)
    LinkedGraph(int N);

    // getters (structural properties such as degree distr and percolation metrics)

    std::vector<int> getClusterDistribution() const;

    std::vector<int> getDegreeDistribution() const;

    int getLCC();

    double getAverageClusterSize() const;

    int getSecondLargestClusterSize() const;

    // Add random edge (Erods-Renyi)
    void addRandomEdge();
    void addRandomEdges(int numEdges);

    // Standard Achlioptas process, product rule
    void addRandomProductRule();
    void addRandomEdgesProductRule(int);
    
    // Standard Achlioptas process, sum rule
    void addRandomSumRule();
    void addRandomEdgesSumRule(int);
    
    // BF rule
    void addEdgeBFRule();
    void addEdgesBFRule(int);

    // Scale-free networks, random edges
    void addEdgeSF(std::vector<int>&);
    void addEdgesSF(int n, std::vector<int>&);

    // Product rule for scale-free networks
    void addEdgeSFPR(std::vector<int>&);
    void addEdgesSFPR(int n, std::vector<int>&);

    // Find the root of a node
    Node* findRoot(Node* node);
};