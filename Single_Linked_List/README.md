# 🧩 Linked List Operations in C

This project implements a **singly linked list** in C with various operations such as insertion, deletion, reversal, and concatenation.  
It provides a menu-driven interface for easy interaction with the linked list data structure.

---

## 📘 Overview

A **linked list** is a linear data structure where elements (called nodes) are connected using pointers.  
Each node contains:
- **Data** – the actual value stored.
- **Pointer** – a reference to the next node in the list.

---

## ⚙️ Features

✅ Create a linked list with multiple nodes  
✅ Insert elements:
- At the beginning
- At the end
- At any specific position  

✅ Delete elements:
- From the beginning
- From the end
- From any position  

✅ Reverse a linked list and store it separately  
✅ Concatenate two linked lists (original + reversed)  
✅ Display the entire linked list  
✅ Menu-driven and user-friendly interface  

---

## 🧠 Concepts Used

- **Structures (`struct`)** for node representation  
- **Dynamic memory allocation (`malloc`, `free`)**  
- **Pointers** for traversal and linking  
- **Modular functions** for each operation  

---

## 🧩 Functions Summary

| Function | Description |
|-----------|-------------|
| `createNode(int data)` | Creates a new node dynamically |
| `insertEnd(struct Node* head, int data)` | Inserts node at the end |
| `insertFirst(struct Node* head, int data)` | Inserts node at the beginning |
| `insertCustom(struct Node* head, int data, int pos)` | Inserts node at a specific position |
| `displayList(struct Node* head)` | Displays all elements in the linked list |
| `deleteStart(struct Node* head)` | Deletes the first node |
| `deleteEnd(struct Node* head)` | Deletes the last node |
| `deleteNode(struct Node* head, int pos)` | Deletes node at a specific position |
| `reverseList(struct Node* head)` | Reverses a linked list |
| `concatenate(struct Node* head1, struct Node* head2)` | Combines two linked lists |

---


