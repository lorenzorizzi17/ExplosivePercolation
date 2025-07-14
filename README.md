# ExplosivePercolation

Percolative processes were initially introduced on specific and regular networks (e.g. D-dimensional lattices) to model physical phenomena such as percolation of water in porous stones. However, nothing prevents us from applying the percolation’s paradigm to arbitrary network topologies. Defining $p$ as the probability that a randomly chosen edge (or node) is removed from the network, then a classical result from percolation
theory is that, for certain network topologies, a phase transition (PT) occurs as $p$ is varied. A frequently used *order parameter* for this system is the percolation strength $S$, i.e. the probability that a randomly chosen node belongs to the GCC (giant connected component): below $p_c$, the largest connected component scales linearly with the size $N$, above $p_c$ it scales sub-linearly and no percolating cluster exists
It is a standard result that classical random percolation on networks displays a continuous phase transitions, meaning that, at criticality, $S(p_c) = 0$ and the order parameter has no discontinuous behaviour around the critical point. 

However, in 2009, an inspiring [article](https://www.science.org/doi/10.1126/science.1167782) from Achlioptas et al. proposed a new type of percolation process that, allegedly, leads to a discontinuous type of transition (called *explosive percolation* for its abrupt nature). Later studies have however managed to prove that explosive percolation is actually a continuous one. In the present code, we are going to explore and simulate Achlioptas process(es) on various network topologies to recreate and study the explosive percolation behaviour


### Order parameter S