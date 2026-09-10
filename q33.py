#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
import os
# 1. Define the function and its first derivative
def f(x):
    return np.exp(x) - 2

def df(x):
    return np.exp(x)

# 2. Parameters given in the problem
x0 = 1.0  # Initial guess
f_x0 = f(x0)
df_x0 = df(x0)

# 3. Setting up data points for the visualization plot
x_vals = np.linspace(0.2, 1.5, 500)
y_vals = f(x_vals)

# Define the equation for the tangent line at x0 = 1
# y - f(x0) = f'(x0) * (x - x0) -> y = f'(x0)*(x - x0) + f(x0)
tangent_line = df_x0 * (x_vals - x0) + f_x0

# 4. Creating and Styling the Figure
plt.figure(figsize=(8, 6))

# Plot the nonlinear function curve f(x) = e^x - 2
plt.plot(x_vals, y_vals, label=r'$f(x) = e^x - 2$', color='#1f77b4', linewidth=2.5)

# Plot the tangent line drawn from x0 to reveal the intercept x1
plt.plot(x_vals, tangent_line, label='Tangent line at $x_0=1$', color='#ff7f0e', linestyle='--', linewidth=1.5)

# Highlight reference axes lines
plt.axhline(0, color='black', linewidth=1, linestyle=':')
plt.axvline(np.log(2), color='green', linewidth=1, linestyle='-.', label=r'Exact Root $\ln(2) \approx 0.693$')

# Scatter markers to visually track the sequence path
plt.scatter([x0], [f_x0], color='red', zorder=5, s=80, label=r'Initial Guess $(x_0, f(x_0))$')

# Draw a drop line connecting the tangent alignment from x0 down to the curve axis
plt.vlines(x0, 0, f_x0, colors='gray', linestyles='dashed', alpha=0.7)

# Labels, Annotations and Layout configurations
plt.title('Newton-Raphson Method Visualization ($e^x - 2 = 0$)', fontsize=14, fontweight='bold', pad=15)
plt.xlabel('x value', fontsize=12)
plt.ylabel('y value', fontsize=12)
plt.xlim(0.4, 1.3)
plt.ylim(-1.5, 2.0)
plt.grid(True, alpha=0.3)
plt.legend(loc='upper left', fontsize=10)

# Adjust layouts perfectly prior to rendering/saving assets
plt.tight_layout()

# 5. Exporting as a vector PDF document format
output_filename = "new_plot.pdf"
plt.savefig(output_filename, format='pdf', dpi=300)
os.system("termux-open new_plot.pdf")


