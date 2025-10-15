# 🌀 Circular Linked List in C

## 📘 Overview

This project implements a **Circular Linked List (CLL)** in C, allowing various **insertion, deletion, reversal, and concatenation** operations.
Unlike a normal linked list, the **last node points back to the head**, forming a circular connection.

This program uses **dynamic memory allocation** and provides an interactive **menu-driven interface** for users to perform all list operations easily.

---

## ⚙️ Features

### 🔹 Creation

* Create a circular linked list with multiple nodes.
* Each node contains an integer data value.

### 🔹 Insertion Operations

1. **Insert at Beginning** — Adds a new node at the start of the list.
2. **Insert at End** — Appends a new node to the end of the list.
3. **Insert at Custom Position** — Inserts a node at a specific position in the list.

### 🔹 Deletion Operations

1. **Delete First Node** — Removes the head node.
2. **Delete Last Node** — Removes the last node in the circular structure.
3. **Delete Custom Node** — Deletes a node at a user-specified position.

### 🔹 Other Functionalities

* **Display List** — Prints all nodes in the list in a circular fashion.
* **Reverse List** — Reverses the order of elements in a new circular linked list.
* **Concatenate Lists** — Joins the reversed list with the original list.
* **Exit** — Cleanly terminates the program.

---

## 🧠 Core Concepts Used

* **Structures in C** – Used to define `Node` (data + pointer to next).
* **Dynamic Memory Allocation** – Uses `malloc()` for node creation.
* **Pointers** – For node linking and traversal.
* **Loops & Conditional Logic** – For circular traversal and user menu handling.

---

## 🧩 Data Structure Used

```c
struct Node {
    int data;
    struct Node* next;
};
```

* `data`: Holds the value of the node.
* `next`: Points to the next node in the list (or back to head if it’s the last node).

---

## 🖥️ How the Program Works

1. The program starts with an **empty list** (`head = NULL`).
2. The user is presented with a **menu** of operations.
3. Based on input, appropriate functions like `insertEnd()`, `deleteNode()`, or `reverseList()` are called.
4. The program keeps running until the user chooses to exit.

---

## 📋 Example Menu

```
Pick one:
1. Create Linked List (multiple nodes)
2. Display the Linked List
3. Insert an element
4. Delete a node
5. Reverse the list
6. Concatenate reversed list to original
7. Exit
```

---

## 🔍 Sample Output

```
Pick one:
1. Create Linked List (multiple nodes)
Enter number of nodes: 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
List created!
Linked List: 10 -> 20 -> 30 -> head

Pick one:
3. Insert an element
1. Insert at first
2. Insert at last
3. Insert at position
Enter choice: 1
Enter data: 5
Linked List: 5 -> 10 -> 20 -> 30 -> head
```

---

## 🧮 Functions Summary

| Function         | Description                        |
| ---------------- | ---------------------------------- |
| `createNode()`   | Creates a new node dynamically     |
| `insertEnd()`    | Inserts a node at the end          |
| `insertFirst()`  | Inserts a node at the start        |
| `insertCustom()` | Inserts at a specific position     |
| `displayList()`  | Prints all nodes in circular order |
| `deleteStart()`  | Deletes first node                 |
| `deleteEnd()`    | Deletes last node                  |
| `deleteNode()`   | Deletes node at specific position  |
| `reverseList()`  | Reverses the circular linked list  |
| `concatenate()`  | Concatenates two circular lists    |

---

## 🧰 Compilation and Execution

### **Compile:**

```bash
gcc circular_linked_list.c -o circular_list
```

### **Run:**

```bash
./circular_list
```

---

## 📈 Advantages of Circular Linked List

* Efficient traversal (can loop through the list endlessly).
* No NULL termination (simplifies operations like concatenation).
* Useful for buffering, round-robin scheduling, or playlist loops.

---

## ⚠️ Notes

* Always ensure at least one node exists before using operations like delete or reverse.
* Since it uses dynamic memory allocation, always handle list termination properly to avoid memory leaks.

---

## 🏁 Conclusion

This program provides a **complete hands-on demonstration** of circular linked list operations in C.
It helps understand **dynamic memory**, **pointer manipulation**, and **linked data structure logic** effectively.
