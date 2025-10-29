import matplotlib.pyplot as plt

# Linear Search Performance Plot

# Array sizes (number of elements)
array_sizes = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000]

# Corresponding average time taken in seconds
avg_times = [0.000000, 0.000000, 0.000001, 0.000002, 0.000005,
             0.000013, 0.000019, 0.000023, 0.000026, 0.000028]

# Create a new figure with custom dimensions
plt.figure(figsize=(10, 6))

# Plot the data with smooth line and circle markers
plt.plot(array_sizes, avg_times, marker='o', linestyle='-', color='royalblue', linewidth=2)

# Add chart title and axis labels
plt.title("Linear Search Performance: Array Size vs Time Taken", fontsize=14, fontweight='bold')
plt.xlabel("Array Size (n)", fontsize=12)
plt.ylabel("Average Time Taken (seconds)", fontsize=12)

# Add grid for better readability
plt.grid(True, linestyle='--', alpha=0.6)

# Annotate each data point with its value
for n, t in zip(array_sizes, avg_times):
    plt.text(n, t + 0.000002, f"{t:.6f}", ha='center', fontsize=8, color='darkblue')

# Adjust layout for cleaner display
plt.tight_layout()

# Display the plot
plt.show()
