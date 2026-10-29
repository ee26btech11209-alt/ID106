import matplotlib
matplotlib.use('Agg')  # Must be called before importing pyplot to run safely in Termux
import matplotlib.pyplot as plt
import numpy as np

# 1. Define sampling parameters (Fs = 40 Hz, first 10 samples from n = 0 to 9)
Fs = 40
n = np.arange(10)
t_samples = n / Fs

# 2. Compute sample values for both signals
x1_samples = np.cos(20 * np.pi * t_samples)
x2_samples = np.cos(100 * np.pi * t_samples)

# 3. Programmatically evaluate each option
# Note: Questions use 1-based indexing (e.g., 4th sample is index 3)

# Option A: All of the first three samples (indices 0, 1, 2) x1 > x2
opt_A = np.all(x1_samples[0:3] > x2_samples[0:3])

# Option B: All of the last three samples (indices 7, 8, 9) x1 > x2
opt_B = np.all(x1_samples[7:10] > x2_samples[7:10])

# Option C: All of the samples (indices 0 to 9) x2 > x1
opt_C = np.all(x2_samples > x1_samples)

# Option D: All of the fourth to seventh samples (indices 3, 4, 5, 6) x1 == x2
# Using np.isclose to protect against microscopic floating-point rounding errors
opt_D = np.all(np.isclose(x1_samples[3:7], x2_samples[3:7]))

# Print the text results to the terminal
print("====================================================")
print("             OPTION EVALUATION RESULTS              ")
print("====================================================")
print(f"Option (A) is TRUE? -> {opt_A}")
print(f"Option (B) is TRUE? -> {opt_B}")
print(f"Option (C) is TRUE? -> {opt_C}")
print(f"Option (D) is TRUE? -> {opt_D}")
print("====================================================")

# 4. Generate and save the plot
t_continuous = np.linspace(0, 0.25, 1000)
x1_continuous = np.cos(20 * np.pi * t_continuous)
x2_continuous = np.cos(100 * np.pi * t_continuous)

plt.figure(figsize=(10, 5))
plt.plot(t_continuous, x1_continuous, label=r'$x_1(t) = \cos(20\pi t)$', color='blue', alpha=0.7)
plt.plot(t_continuous, x2_continuous, label=r'$x_2(t) = \cos(100\pi t)$', color='orange', alpha=0.4, linestyle='--')
plt.stem(t_samples, x1_samples, linefmt='k-', markerfmt='ko', basefmt='k-', label='Sampled Points (Identical)')

plt.title('Aliasing Analysis: Discrete Samples vs Continuous Signals')
plt.xlabel('Time (seconds)')
plt.ylabel('Amplitude')
plt.legend(loc='upper right')
plt.grid(True, linestyle=':', alpha=0.6)

# Save the plot image locally
output_file = 'plot.png'
plt.savefig(output_file, dpi=150, bbox_inches='tight')
print(f"\n[Success] Visualization saved to your directory as: {output_file}")

