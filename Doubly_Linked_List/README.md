# 🔗 Doubly Linked List in C

This program demonstrates the implementation of a **Doubly Linked List (DLL)** in C, providing all major operations such as **insertion**, **deletion**, **reversal**, and **concatenation** through a **menu-driven interface**.  
Each node contains pointers to both its **previous** and **next** nodes, allowing bidirectional traversal and efficient manipulation.

---

## 🧱 Structure Definition

Each node in the list contains:
```c
struct Node {
    int data;              // Data value of the node
    struct Node* next;     // Pointer to the next node
    struct Node* prev;     // Pointer to the previous node
};
````

---

## ⚙️ Core Functionalities

### 🧩 1. Node Creation

* Dynamically allocates memory for each new node.
* Initializes both `next` and `prev` pointers to `NULL`.

### ➕ 2. Insertion Operations

| Function         | Description                                      |
| ---------------- | ------------------------------------------------ |
| `insertFirst()`  | Inserts a new node at the beginning of the list. |
| `insertEnd()`    | Inserts a new node at the end of the list.       |
| `insertCustom()` | Inserts a new node at a user-defined position.   |

💡 *All insert operations automatically adjust `prev` and `next` pointers.*

---

### ➖ 3. Deletion Operations

| Function        | Description                           |
| --------------- | ------------------------------------- |
| `deleteStart()` | Deletes the first node from the list. |
| `deleteEnd()`   | Deletes the last node.                |
| `deleteNode()`  | Deletes a node at a given position.   |

🧹 *Memory for deleted nodes is properly freed to avoid leaks.*

---

### 🔁 4. Reverse the List

| Function        | Description                                                                           |
| --------------- | ------------------------------------------------------------------------------------- |
| `reverseList()` | Reverses the entire linked list by swapping `next` and `prev` pointers for each node. |

🪞 Creates a **separate reversed copy** using `cloneList()` for safe concatenation.

---

### 🔗 5. Concatenate Two Lists

| Function        | Description                                         |
| --------------- | --------------------------------------------------- |
| `concatenate()` | Joins the normal list and reversed list end-to-end. |

---

### 👀 6. Display the List

| Function        | Description                                                                                               |
| --------------- | --------------------------------------------------------------------------------------------------------- |
| `displayList()` | Prints all elements of the list in a forward direction using bidirectional traversal (`prev` and `next`). |

---

## 🧮 Features

* Menu-driven interface for easy interaction
* Supports dynamic node creation and manipulation
* Separate copy and reverse functionalities to preserve original data
* Concatenation of two lists (normal + reversed)
* Proper error handling and invalid position checks
* Frees unused memory to prevent leaks

---

## 💻 How to Run

### 🛠 Prerequisites

* GCC compiler installed on your system

### 🧾 Steps

```bash
# Navigate to the folder
cd DSA/Doubly_Linked_List

# Compile the program
gcc Doubly_Linked_List.c -o dll

# Run the executable
./dll
```

---

## 🧠 Example Output

```
Pick one of the following:
1. Create Linked List (multiple nodes)
2. Display the whole Linked list
3. Insert an element in the list
4. Deletion of a node from List
5. Reverse the Linked List (and save separately)
6. Concatenate reversed list to normal list
7. Exit
Enter your choice: 1
How many nodes do you want to create? 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Nodes created successfully!
List: 10 <-> 20 <-> 30 <-> NULL
```

---

## 🔍 Example Operations

| Operation            | Input | Output                                |
| -------------------- | ----- | ------------------------------------- |
| Insert at Start      | 5     | 5 <-> 10 <-> 20 <-> 30                |
| Insert at End        | 40    | 10 <-> 20 <-> 30 <-> 40               |
| Delete at Position 2 | -     | 10 <-> 30 <-> 40                      |
| Reverse List         | -     | 40 <-> 30 <-> 10                      |
| Concatenate          | -     | 10 <-> 20 <-> 30 <-> 30 <-> 20 <-> 10 |

---

## 📊 Time & Space Complexity

| Operation     | Time Complexity                     | Space Complexity |
| ------------- | ----------------------------------- | ---------------- |
| Insertion     | O(1) at start/end, O(n) at position | O(1)             |
| Deletion      | O(1) at start/end, O(n) at position | O(1)             |
| Reversal      | O(n)                                | O(1)             |
| Concatenation | O(n)                                | O(1)             |
| Display       | O(n)                                | O(1)             |

---

