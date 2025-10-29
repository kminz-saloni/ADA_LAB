import matplotlib.pyplot as plt

input_sizes = [100, 300, 600, 900, 1200, 1500, 1800]
duration_secs = [0.000173, 0.002334, 0.011884, 0.019764, 0.038526, 0.072840, 0.091639]

plt.plot(input_sizes, duration_secs, marker='x', color='blue')
plt.xlabel('Size of Array')
plt.ylabel('Sorting Duration (seconds)')
plt.title('Insertion Sort Execution Time')
plt.grid(True)
plt.show()
