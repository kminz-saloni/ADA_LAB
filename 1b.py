import matplotlib.pyplot as plt

n_values = [10, 50, 100, 500, 1000, 3000, 5000, 7000, 10000, 20000]
time_values = [0.00000001, 0.00000001, 0.00000002, 0.00000002, 0.00000003,
               0.00000003, 0.00000004, 0.00000004, 0.00000004, 0.00000004]

plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='red')
plt.title('Binary Search: Array Size vs Time Taken')
plt.xlabel('Array Size (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)

for n, t in zip(n_values, time_values):
    plt.text(n, t + 0.0000005, f"{t:.6f}", ha='center', fontsize=8)

plt.tight_layout()
plt.show()
