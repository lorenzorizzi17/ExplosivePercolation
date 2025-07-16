# Explosive Percolation and Achlioptas processes

Percolative processes were originally introduced on regular structures (e.g., D-dimensional lattices) to model physical phenomena such as fluid flow through porous media. However, the percolation paradigm can be extended to arbitrary network topologies. Letting $p$ denote the probability that a randomly chosen edge (or node) is removed, classical percolation theory predicts that certain networks undergo a phase transition (PT) as $p$ varies. A common order parameter is the percolation strength $S$, defined as the probability that a randomly selected node belongs to the giant connected component (GCC). Below the critical threshold $p_c$, the largest component scales linearly with the system size $N$; above $p_c$, it scales sub-linearly and no spanning cluster exists.
 

In standard random percolation, this transition is continuous: at criticality, $S(p_c) = 0$, and the order parameter varies smoothly around $p_c$. However, in 2009, an inspiring [article](https://www.science.org/doi/10.1126/science.1167782) from Achlioptas et al. proposed a new type of percolation process that, allegedly, leads to a discontinuous type of transition (called *explosive percolation* for its abrupt nature). Later studies have however managed to prove that explosive percolation is actually a continuous one. In the present code, we are going to explore and simulate Achlioptas process(es) on various network topologies to recreate and study the explosive percolation behaviour

**N.B.** A report of the work is provided in `report.pdf`. Some plots are quite large, so the PDF file may take a while to load.

### Order parameter S

<img src="https://github.com/user-attachments/assets/d6cec67d-8f61-4c90-94a8-453e413a624e" alt="S_page-0001" width="700"/>

The size of the largest connected component (LCC) is monitored as more and more edges are added. The product rule and sum rule, as proposed by Achlioptas, appear to lead to an abrupt and discontinuous phase transition.


### Code implementation

To simulate the percolative growth procedure, we will employ the [Newman-Ziff](https://journals.aps.org/prl/abstract/10.1103/PhysRevLett.85.4104) algorithm, which is particularly efficient because it combines the generative phase (adding edges) with the cluster detection algorithm. A specific class, `LinkedGraph`, is implemented, containing a `std::vector` of `Node` objects, where each `Node` features a pointer to another `Node` object. Initially, each node points to a `nullptr`. As edges are progressively added to the graph, nodes are gradually connected and merged into common clusters. Specifically, when an edge is created between two nodes, one of the node pointers is updated to point to the newly added neighbor. This way, it becomes easy to retrieve the list of clusters in the graph.