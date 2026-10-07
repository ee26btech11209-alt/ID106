import os
import matplotlib.pyplot as plt
import numpy as np

# Calculated parameters for differentiability
a = 5.0
b = -2.0

print(f"a = {a}")
print(f"b = {b}")


# Piecewise function definition
def f(x):
    return np.piecewise(
        x, [x < 1, x >= 1], [lambda x: a * x + b, lambda x: x**3 + x**2 + 1]
    )


# Generate data points
x = np.linspace(-2, 2, 400)
y = f(x)

# Plot creation
plt.figure(figsize=(8, 5))
plt.plot(x, y, label=r"$f(x)$", color="blue", linewidth=2)
plt.axvline(
    x=1,
    color="gray",
    linestyle="--",
    alpha=0.7,
    label="Transition point (x = 1)",
)
plt.scatter([1], [3], color="red", zorder=5, label="Point (1, 3)")

plt.title("Plot of Differentiable Piecewise Function $f(x)$")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.grid(True, linestyle=":", alpha=0.6)
plt.legend()

# Save plot image locally
output_file = "plot.png"
plt.savefig(output_file, dpi=300, bbox_inches="tight")
plt.close()

# Auto-open in Termux using termux-open
os.system(f"termux-open {output_file}")

