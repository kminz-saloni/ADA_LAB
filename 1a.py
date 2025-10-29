import matplotlib.pyplot as plt

# Input sizes and corresponding linear search times (in seconds)
n_values = [1000, 10000, 100000, 1000000, 10000000]
linear_times_seconds = [0.000002, 0.000027, 0.000308, 0.003087, 0.000022]

# Convert time values to microseconds for better visualization
linear_times_micro = [t * 1e6 for t in linear_times_seconds]

# Plotting the performance graph
plt.plot(n_values, linear_times_micro, label="Linear Search", marker='o', color='blue')

# Labeling the axes and adding a title
plt.xlabel("Number of elements (n)")
plt.ylabel("Time taken (μs) = microseconds")
plt.title("Linear Search Performance")

# Display legend and grid
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
