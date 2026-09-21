import os
import numpy as np
import matplotlib.pyplot as plt

# 1. Define the system parameters (Thermometer / RC Circuit Equivalent)
tau = 40 
target_fraction = 0.95

# 2. Calculate the theoretical target time
t_target = -tau * np.log(1 - target_fraction)
rounded_time = round(t_target)

# Print the theoretical values directly to the terminal
print("=" * 45)
print(f"Theoretical Target Time: {t_target:.2f} seconds")
print(f"Rounded Answer (Nearest Integer): {rounded_time} seconds")
print("=" * 45)

# 3. Generate data for the line plot
t = np.linspace(0, 200, 1000)
v_response = 1 - np.exp(-t / tau)

# 4. Create the plot
plt.figure(figsize=(8, 5))
plt.plot(t, v_response, label="RC Charging Response", color="blue", linewidth=2)

# Mark the 95% threshold steady-state target point
plt.plot(t_target, target_fraction, marker="o", color="red", markersize=8, 
         label=f"95% Output ({rounded_time}s)")

# Draw dashed tracking lines to the axes for visual reference
plt.axvline(x=t_target, color="red", linestyle="--", alpha=0.6)
plt.axhline(y=target_fraction, color="red", linestyle="--", alpha=0.6)

# Graph labels and styling
plt.title("First-Order Step Response (RC Equivalent Circuit)")
plt.xlabel("Time (seconds)")
plt.ylabel("Normalized Output / Voltage (V / V_s)")
plt.grid(True, linestyle=":", alpha=0.6)
plt.legend(loc="lower right")

# 5. Save the output
output_filename = "rc_plot.png"
plt.savefig(output_filename, dpi=150)



os.system(f"termux-open {output_filename}")

