# 🧩 Graph Representation and Traversal Algorithms in C

This folder contains C implementations of **graph data structures** and two fundamental **graph traversal algorithms** — **Breadth First Search (BFS)** and **Depth First Search (DFS)**.

---

## 📁 File Overview

| File Name | Description |
|------------|-------------|
| **`graph.c`** | Demonstrates graph creation and manipulation using an **Adjacency List** representation. Supports adding and deleting vertices and edges. |
| **`bfs.c`** | Performs **Breadth First Search (BFS)** traversal using an **Adjacency Matrix** and a **Queue**. |
| **`dfs.c`** | Performs **Depth First Search (DFS)** traversal using an **Adjacency Matrix** and a **Stack**. |

---

## 🧱 1. Graph Representation (`graph.c`)

### 🔹 Concept
A **graph** is a collection of **vertices (nodes)** and **edges (connections)**.  
Here, it’s represented using an **Adjacency List**, where each vertex stores a linked list of its connected vertices.

### ⚙️ Features
- Insert an **edge** between two vertices  
- Delete a **node (vertex)** and all its connections  
- Display the **Adjacency List** structure  

### 🧩 Core Functions
| Function | Description |
|-----------|-------------|
| `createNode(int data)` | Creates a new vertex node |
| `insertEdge()` | Adds a bidirectional edge between two vertices |
| `deleteEdge()` | Removes an edge between two given vertices |
| `deleteNode()` | Deletes a vertex and all its connected edges |
| `displayAdjList()` | Displays the adjacency list of the graph |

### 🧠 Example
```

--- Menu ---

1. Insert Edge
2. Delete Node
3. Display Adjacency List
4. Exit
   Enter your choice: 1
   Enter source and destination vertices (src dest): 0 1
   Edge from 0 to 1 inserted.

```

---

## 🔍 2. Breadth First Search (`bfs.c`)

### 🔹 Concept
BFS explores vertices **level by level**, using a **queue**.  
It’s ideal for finding the shortest path in unweighted graphs.

### ⚙️ Key Points
- Uses an **Adjacency Matrix** to represent the graph  
- Maintains a **Visited Array** to avoid revisiting nodes  
- Uses a **Queue** for traversal order  

### 🧩 Core Functions
| Function | Description |
|-----------|-------------|
| `enqueue()` / `dequeue()` | Manage nodes in the queue |
| `bfs(int start)` | Performs BFS starting from a chosen vertex |

### 🧠 Example
```

Enter number of vertices - 4
Enter number of edges - 3
Enter edge (src dest) - 0 1
Enter edge (src dest) - 0 2
Enter edge (src dest) - 1 3

BFS starting from vertex 0:
0 1 2 3

```

---

## 🔎 3. Depth First Search (`dfs.c`)

### 🔹 Concept
DFS explores as far as possible along one branch before backtracking, using a **stack**.  
It’s commonly used for **pathfinding**, **cycle detection**, and **component analysis**.

### ⚙️ Key Points
- Uses **Adjacency Matrix** representation  
- Employs a **Stack** for traversal  
- Utilizes a **Visited Array** to track explored nodes  

### 🧩 Core Functions
| Function | Description |
|-----------|-------------|
| `push()` / `pop()` | Manage nodes in stack |
| `dfs(int start)` | Performs DFS from a chosen starting vertex |

### 🧠 Example
```

Enter number of vertices: 4
Enter number of edges: 3
Enter edge (src dest): 0 1
Enter edge (src dest): 0 2
Enter edge (src dest): 1 3

DFS starting from vertex 0:
DFS Path: 0 2 1 3

````

---

## 📊 Comparison Between BFS and DFS

| Feature | BFS | DFS |
|----------|-----|-----|
| Data Structure Used | Queue | Stack |
| Traversal Type | Level Order | Depth First |
| Recursion Used | No | Optional (can be recursive or iterative) |
| Suitable For | Shortest Path, Level-wise traversal | Pathfinding, Topological Sort |
| Space Complexity | O(V) | O(V) |
| Time Complexity | O(V + E) | O(V + E) |

---

## 💻 How to Run

### 🛠 Prerequisites
- GCC Compiler installed on your system

### ▶️ Steps
```bash
# Navigate to the folder
cd DSA/Graph

# Compile and run any program
gcc graph.c -o graph
./graph

gcc bfs.c -o bfs
./bfs

gcc dfs.c -o dfs
./dfs
````

---

## 🧩 Folder Structure

```
Graph/
│
├── graph.c        # Adjacency List creation, insertion, deletion, display
├── bfs.c          # Breadth First Search using adjacency matrix
├── dfs.c          # Depth First Search using adjacency matrix
└── README.md      # (this file)
```

---
