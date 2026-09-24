import numpy as np
import matplotlib.pyplot as plt
import os
import subprocess

# 1. Represent the two curves in homogeneous matrix forms
# Curve 1 (S1): x^2 - y = 0
M1 = np.array([
    [1.0,  0.0,  0.0],
    [0.0,  0.0, -0.5],
    [0.0, -0.5,  0.0]
])

# Curve 2 (S2): x^2 + 2x + y + 1 = 0
M2 = np.array([
    [1.0,  0.0,  1.0],
    [0.0,  0.0,  0.5],
    [1.0,  0.5,  1.0]
])

# 2. Compute the Radical Axis / Common Chord line via matrix subtraction
M_line = M1 - M2

a = 2 * M_line[0, 2]
b = 2 * M_line[1, 2]
c = M_line[2, 2]

print(f"Calculated Common Chord Line: {a}x + {b}y + {c} = 0")

# 3. Generate data for plotting
x_vals = np.linspace(-3, 2, 400)
y1_vals = x_vals**2
y2_vals = -x_vals**2 - 2*x_vals - 1
y_chord = (-a * x_vals - c) / b

# 4. Create the graph
plt.figure(figsize=(7, 6))
plt.plot(x_vals, y1_vals, label=r'$y = x^2$', color='blue', lw=2)
plt.plot(x_vals, y2_vals, label=r'$y = -x^2 - 2x - 1$', color='red', lw=2)
plt.plot(x_vals, y_chord, label='Common Chord Line', color='green', linestyle='--', lw=2)

# Graph styling
plt.axhline(0, color='black', linewidth=0.8, linestyle=':')
plt.axvline(0, color='black', linewidth=0.8, linestyle=':')
plt.xlim(-3, 2)
plt.ylim(-4, 4)
plt.grid(True, linestyle='--', alpha=0.5)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Curves & Matrix Solution')
plt.legend()

# 5. Save the output and open it in Android using Termux API
output_filename = "plot.png"
plt.savefig(output_filename, bbox_inches='tight', dpi=150)
plt.close()
print(f"Graph successfully saved as '{output_filename}'")

# Call termux-open to visually pop open the photo directly on your phone screen
try:
    subprocess.run(["termux-open", output_filename], check=True)
except FileNotFoundError:
    print("\nNote: Plot generated! To see it directly on your screen, ensure you have run 'pkg install termux-api'.")

