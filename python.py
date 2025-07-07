import numpy as np
import matplotlib.pyplot as plt

filename = "./data/ClusterDistribution/ER_10000.txt" 
title = "Distribuzione dei cluster (log-log)"

with open(filename, 'r') as f:
    data = [int(line.strip()) for line in f if line.strip().isdigit()]

data = [d for d in data if d > 0]


counts, bins = np.histogram(data, bins='auto') 
bin_centers = 0.5 * (bins[1:] + bins[:-1])

plt.figure(figsize=(8, 6))
plt.loglog(bin_centers, counts, marker='o', linestyle='-', color='b')
plt.xlabel("Valore")
plt.ylabel("Frequenza")
plt.title(title)
plt.grid(True, which="both", ls="--", lw=0.5)
plt.tight_layout()
plt.show()
