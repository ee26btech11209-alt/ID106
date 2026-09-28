import numpy as np

# Define the matrix
A = np.array([[9, 15], [15, 50]])

# Perform Cholesky decomposition to get lower triangular matrix L
L = np.linalg.cholesky(A)

print("Lower Triangular Matrix L:")
print(L)

# Accessing |l22| (1-based index l22 corresponds to 0-based index [1, 1])
l22 = abs(L[1, 1])
print(f"\n|l22| = {int(l22)}")

