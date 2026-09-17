#D.nikhil
#17 september 2026


import os
import matplotlib.pyplot as plt
import numpy as np

# Define x values for plotting
x = np.linspace(-5, 10, 400)

# Rearranging equations to express y in terms of x:
# 2x + 3y = 6 -> y = (6 - 2x) / 3
y1 = (6 - 2 * x) / 3

# For k = 4: 4x + 6y = 12 -> y = (12 - 4x) / 6
y2_k4 = (12 - 4 * x) / 6

# For k = 6: 4x + 6y = 18 -> y = (18 - 4x) / 6
y2_k6 = (18 - 4 * x) / 6

# Create the plot
plt.figure(figsize=(8, 6))

# Plot the lines
# Note: The k=4 line perfectly overlaps with the original blue line
plt.plot(x, y1, label="2x + 3y = 6", color="blue", linewidth=3)
plt.plot(
    x,
    y2_k4,
    label="4x + 6y = 12 (k=4, Coincident)",
    color="orange",
    linestyle="--",
    linewidth=1.5,
)
plt.plot(
    x, y2_k6, label="4x + 6y = 18 (k=6, Parallel)", color="red", linewidth=2
)

# Plot decoration and formatting
plt.axhline(0, color="black", linewidth=0.8, linestyle=":")
plt.axvline(0, color="black", linewidth=0.8, linestyle=":")
plt.grid(True, linestyle=":", alpha=0.6)
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("System of Linear Equations for k=4 and k=6")
plt.legend()

# Save the plot as an image
image_path = "linear_equations.png"
plt.savefig(image_path, dpi=300)
plt.close()
print(f"Plot saved successfully as '{image_path}'")

# Automatically launch the image viewer via Termux API using os.system
print("Opening the image automatically...")
exit_code = os.system(f"termux-open {image_path}")

if exit_code != 0:
    print("\n[Notice] Automatic open failed.")
    print("Please make sure the 'Termux:API' app is installed on your device.")

