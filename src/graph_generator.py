import pandas as pd
import matplotlib.pyplot as plt

files = [
    ("../results/random_result.csv", "Experiment 1 - Random Arrays", "../graphs/graph_1_random_array.png"),
    ("../results/ascending_result.csv", "Experiment 2A - Ascending Arrays", "../graphs/graph_2_ascending_array.png"),
    ("../results/descending_result.csv", "Experiment 2B - Descending Arrays", "../graphs/graph_2_descending_array.png")
]

strategies = ["First", "Last", "Middle", "Random"]

for csv_file, title, output_file in files:
    data = pd.read_csv(csv_file)
    plt.figure(figsize=(10, 12))

    for strategy in strategies:
        plt.plot(data["size"], data[strategy], label=strategy)

    plt.title(title)
    plt.xlabel("Array Size")
    plt.ylabel("Average Time (microseconds)")
    plt.legend()
    plt.grid(True)
    plt.savefig(output_file)
    plt.close()

    print(f"Saved {output_file}")

print("All graphs generated.")