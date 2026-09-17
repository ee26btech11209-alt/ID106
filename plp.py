import os
import matplotlib
matplotlib.use('Agg') # Required for Termux

import matplotlib.pyplot as plt
import numpy as np

print("=== Linear Equations Plotter ===")

# Simple input taking
k = float(input("Enter k: "))

# Define matrix rows for: ax + by = c
line1 = np.array([2, 3, 6], dtype=float)
line2 = np.array([4, 6, 3 * k], dtype=float)

# Using np.block to construct the matrices
A = np.block([[line1[:2]], [line2[:2]]])
augmented_matrix = np.block([[line1], [line2]])

# Generate data points for the lines
x_vals = np.linspace(-5, 5, 400)
y_vals1 = (6 - 2 * x_vals) / 3
y_vals2 = (3 * k - 4 * x_vals) / 6

# Matrix rank analysis using the new blocked matrices
rank_A = np.linalg.matrix_rank(A)
rank_aug = np.linalg.matrix_rank(augmented_matrix)

if rank_A == rank_aug:
    if rank_A == 2:
        status = "Lines intersect"
    else:
        status = "Lines overlap"
else:
    status = "Lines are parallel"
    
print(f"Status: {status}")

# Plotting setup
plt.figure(figsize=(8, 6))
plt.plot(x_vals, y_vals1, label='2x + 3y = 6', color='blue', linewidth=2)
plt.plot(x_vals, y_vals2, label=f'4x + 6y = 3({k})', color='orange', linestyle='--', linewidth=2)

plt.axhline(0, color='black', linewidth=0.8)
plt.axvline(0, color='black', linewidth=0.8)
plt.grid(True, linestyle=':', alpha=0.6)
plt.title(f'k = {k} ({status})')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()

# Save the file
output_filename = "system_plot.png"
plt.savefig(output_filename, dpi=300)
plt.close()

print(f"Saved as {output_filename}")

os.system(f"termux-open {output_filename}")
