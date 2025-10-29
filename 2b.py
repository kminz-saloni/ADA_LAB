import matplotlib.pyplot as plt

n = [1000, 3000, 6000, 10000, 15000, 20000, 25000]
time = [0.000134, 0.000442, 0.000956, 0.001668, 0.002665, 0.003652, 0.005059]

plt.figure(figsize=(10, 6))
plt.plot(n, time, marker='o', color='black', linewidth=2)

plt.title("Quick Sort: Time vs Number of Elements", fontsize=14, fontweight='bold')
plt.xlabel("Number of Elements (n)", fontsize=12)
plt.ylabel("Time Taken (seconds)", fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)

# Add time labels above each data point
for x, y in zip(n, time):
    plt.text(x, y + 0.0001, f"{y:.6f}", ha='center', fontsize=8)

plt.tight_layout()
plt.show()
