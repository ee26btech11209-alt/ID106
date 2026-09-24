#code by nikhil
#september 24 2026
import numpy as np

# Define the matrix P
P = np.array([
    [1, 0, 1],
    [0, 1, 0],
    [1, 0, 1]
])

# Compute eigenvalues and eigenvectors
eigenvalues, eigenvectors = np.linalg.eig(P)

# Display the results
print("Eigenvalues:")
print(eigenvalues)

print("\nEigenvectors (column-wise):")
print(eigenvectors)

