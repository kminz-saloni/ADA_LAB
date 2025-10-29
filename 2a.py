import matplotlib.pyplot as plt

n = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000]
time = [0.000012, 0.000020, 0.000032, 0.000106, 0.000269,
        0.000967, 0.001489, 0.001926, 0.002205]

plt.figure(figsize=(10, 6))
plt.plot(n, time, marker='o', color='black', linewidth=2)
plt.title("Merge Sort: Time vs Number of Elements", fontsize=14, fontweight='bold')
plt.xlabel("Number of Elements (n)", fontsize=12)
plt.ylabel("Time Taken (seconds)", fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)

# Show data values on each point
for x, y in zip(n, time):
    plt.text(x, y + 0.00005, f"{y:.6f}", ha='center', fontsize=8)

plt.tight_layout()
plt.show()
