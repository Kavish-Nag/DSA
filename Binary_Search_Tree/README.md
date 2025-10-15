# 🌳 Binary Search Tree (BST) Operations in C

This program implements a **Binary Search Tree (BST)** in C language with basic operations like **insertion**, **tree traversals** (inorder, preorder, postorder), and **searching**.
It provides a simple **menu-driven interface** for user interaction.

---

## 🧠 Features

* ✅ Create and insert nodes in a BST
* ✅ Perform **Inorder**, **Preorder**, and **Postorder** traversals
* ✅ Search for an element in the tree
* ✅ Efficient recursive implementation
* ✅ User-friendly menu for repeated operations

---

## ⚙️ Functions Explained

### 1. `createBT(int value)`

Creates a new binary tree node with the given data and initializes its left and right pointers to `NULL`.

### 2. `insert(struct node* root, int value)`

Inserts a node into the BST following BST insertion rules:

* If the value is smaller, it goes to the **left subtree**.
* If the value is larger, it goes to the **right subtree**.

### 3. `inorder(struct node* root)`

Traverses the tree in **Left → Root → Right** order.

> Displays elements in **ascending order**.

### 4. `preorder(struct node* root)`

Traverses the tree in **Root → Left → Right** order.

> Useful for creating a copy of the tree or displaying structure.

### 5. `postorder(struct node* root)`

Traverses the tree in **Left → Right → Root** order.

> Useful for deleting or freeing the tree.

### 6. `Search(struct node* root, int key)`

Searches for a specific element in the BST and returns the node if found; otherwise, returns `NULL`.

---

## 🖥️ Menu Options

| Option | Action                                            |
| :----: | :------------------------------------------------ |
|    1   | Insert a new node                                 |
|    2   | Traverse the BST (Inorder / Preorder / Postorder) |
|    3   | Search for an element                             |

---

## 🧩 Example Output

```
--- MENU ---
1. Insert a new node
2. Traversal of tree
3. Search for an element
Enter your choice: 1
Enter the value to be inserted: 10

--- MENU ---
1. Insert a new node
2. Traversal of tree
3. Search for an element
Enter your choice: 1
Enter the value to be inserted: 5

--- MENU ---
1. Insert a new node
2. Traversal of tree
3. Search for an element
Enter your choice: 2
Traversal Options:
1. Inorder Traversal
2. Preorder Traversal
3. Postorder Traversal
Enter your choice: 1
5 10

Do you want to continue? (1 = Yes / 0 = No): 0
```

---

## 📚 Concepts Used

* **Binary Search Tree properties**
* **Recursion**
* **Dynamic memory allocation** using `malloc`
* **Menu-driven program** with looping and user input

