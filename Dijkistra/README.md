# 🚦 Dijkstra’s Algorithm in C

This program implements **Dijkstra’s Algorithm**, a fundamental graph algorithm used to find the **shortest path from a single source** to all other vertices in a **weighted graph**.

It uses an **Adjacency Matrix** to represent the graph and efficiently calculates the **minimum distance** to each node using the **Greedy approach**.

---

## 🧠 Algorithm Overview

### 🔹 Dijkstra’s Algorithm

* **Purpose:** Find the shortest path from a source vertex to all other vertices in a **weighted** and **connected** graph.
* **Type:** Single-source shortest path algorithm.
* **Key Principle:** Always select the unvisited vertex with the **smallest known distance**, then update its neighbors.

### ⚙️ Steps Involved

1. Initialize all distances to **infinity (`INF`)** and mark all vertices as **unvisited**.
2. Set the distance to the **starting vertex** as `0`.
3. For every iteration:

   * Pick the **unvisited vertex** with the **minimum distance**.
   * Update (relax) the distances to its **adjacent unvisited vertices** if a shorter path is found.
   * Mark the vertex as **visited**.
4. Repeat until all vertices are visited or unreachable.

---

## 🧩 Features

✅ Supports user-defined **graph creation**
✅ Works for **weighted undirected graphs**
✅ Detects and handles **unreachable vertices** (prints “INF”)
✅ Displays **vertex-wise shortest distances** from the source
✅ Simple, clear, and fully interactive command-line program

---

## 🧮 Data Structures Used

| Structure             | Purpose                                             |
| --------------------- | --------------------------------------------------- |
| `int graph[MAX][MAX]` | Adjacency matrix representation of the graph        |
| `int dist[MAX]`       | Stores shortest distances from the source           |
| `int visited[MAX]`    | Keeps track of visited vertices                     |
| `#define INF 9999`    | Represents infinite distance (no direct connection) |

---

## 🧠 Time and Space Complexity

| Parameter            | Complexity                                |
| -------------------- | ----------------------------------------- |
| **Time Complexity**  | O(V²) — due to nested loops over vertices |
| **Space Complexity** | O(V²) — adjacency matrix representation   |

*(For improved performance, adjacency lists with priority queues reduce it to O((V + E) log V).)*

---

## 🖥️ Example Output

```
Enter number of vertices: 5
Enter number of edges: 7
Enter edge (src dest weight): 0 1 4
Enter edge (src dest weight): 0 2 1
Enter edge (src dest weight): 2 1 2
Enter edge (src dest weight): 1 3 1
Enter edge (src dest weight): 2 3 5
Enter edge (src dest weight): 3 4 3
Enter edge (src dest weight): 1 4 7
Enter the starting vertex (0 to 4): 0

Vertex  Distance from Source
0        0
1        3
2        1
3        4
4        7
```

---

## 🧾 Code Structure

| Section               | Description                               |
| --------------------- | ----------------------------------------- |
| `create graph matrix` | Initialize graph with weights or INF      |
| `dijkstra()`          | Core algorithm for finding shortest paths |
| `main()`              | Handles user input and calls `dijkstra()` |

---

## ⚡ Constants Used

| Constant   | Meaning                                   |
| ---------- | ----------------------------------------- |
| `MAX 10`   | Maximum number of vertices supported      |
| `INF 9999` | Large value representing “no direct edge” |

---

## 🧩 Function Summary

| Function                                          | Description                                                                       |
| ------------------------------------------------- | --------------------------------------------------------------------------------- |
| `dijkstra(int graph[MAX][MAX], int n, int start)` | Implements Dijkstra’s shortest path algorithm                                     |
| `main()`                                          | Takes input for vertices, edges, weights, and start node, then runs the algorithm |

---

## 💻 How to Compile and Run

### **Compile:**

```bash
gcc dijkstra.c -o dijkstra
```

### **Run:**

```bash
./dijkstra
```

---

## 🧠 Notes

* Works correctly for **non-negative weighted graphs** only.
* For **directed graphs**, remove the line `graph[dest][src] = weight;`.
* Modify `MAX` for larger graphs (but ensure enough memory).

---


Would you like me to include a **diagram (ASCII or Markdown)** showing the step-by-step working of Dijkstra’s algorithm on a sample graph? It would make your README stand out visually on GitHub.
```
