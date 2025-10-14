````
# 🧩 Sorting Algorithms in C

This folder contains the implementations of **six classic sorting algorithms** in C — covering both **basic** and **advanced** approaches.  
Each program allows you to interactively test the algorithms by entering custom input arrays and choosing sorting techniques.

---

## 📂 Files Overview

| File Name | Description |
|------------|-------------|
| **`Selection_Bubble_Insertion.c`** | Implements **Bubble Sort**, **Selection Sort**, and **Insertion Sort** (both using arrays and pointer logic). |
| **`Merge_Quick.c`** | Implements **Merge Sort** and **Quick Sort** (with multiple pivot selection strategies). |

---

## ⚙️ Algorithms Covered

### 🔹 1. Bubble Sort
- **Logic:** Repeatedly compares adjacent elements and swaps them if they’re in the wrong order.  
- **Complexity:**  
  - Best Case: *O(n)* (when already sorted)  
  - Worst Case: *O(n²)*  
- **Type:** Comparison-based, In-place, Stable

---

### 🔹 2. Selection Sort
- **Logic:** Repeatedly selects the smallest element from the unsorted part and swaps it with the first unsorted element.  
- **Complexity:** *O(n²)* in all cases  
- **Type:** Comparison-based, In-place, Not stable

---

### 🔹 3. Insertion Sort
- **Logic:** Builds a sorted array one element at a time by inserting elements into their correct position.  
- **Complexity:**  
  - Best Case: *O(n)*  
  - Worst Case: *O(n²)*  
- **Type:** Comparison-based, In-place, Stable  
- **Ideal for:** Small datasets or nearly sorted arrays

---

### 🔹 4. Merge Sort
- **Logic:** Uses the **divide and conquer** strategy — divides the array into halves, sorts them recursively, and merges the sorted halves.  
- **Complexity:** *O(n log n)* (in all cases)  
- **Type:** Comparison-based, Not in-place (requires extra memory), Stable

---

### 🔹 5. Quick Sort
- **Logic:** Also uses **divide and conquer** by choosing a pivot element and partitioning the array around it.  
- **Pivot Strategies Included:**
  1. **Mid element**  
  2. **Hoare’s (first element)**  
  3. **Lomuto’s (last element)**  
- **Complexity:**  
  - Best & Average Case: *O(n log n)*  
  - Worst Case: *O(n²)* (when pivot choice is poor)  
- **Type:** Comparison-based, In-place, Not stable

---

## 🧮 Features

- Interactive menu-based programs  
- Demonstrates **array-based** and **pointer-based** sorting implementations  
- Supports multiple sorting techniques in one file  
- User can re-run with different array sizes and elements without restarting  
- Clear output of **unsorted** and **sorted** arrays  

---

## 💻 How to Run

### 🛠 Prerequisites
- GCC compiler installed on your system

### 🧾 Steps
```bash
# Navigate to the Sorting directory
cd DSA/Sorting

# Compile one of the files
gcc Selection_Bubble_Insertion.c -o basic_sort
./basic_sort

# OR

gcc Merge_Quick.c -o advanced_sort
./advanced_sort
````

---

## 🧠 Example Output

```
Enter number of elements of array: 5
Enter 1 element: 34
Enter 2 element: 12
Enter 3 element: 25
Enter 4 element: 8
Enter 5 element: 50

Select a way (1/2/3/4/5/6)
1. Bubble sort.
2. Selection sort.
3. Bubble sort with pointer.
4. Selection sort with pointer.
5. Insertion sort.
6. Insertion sort with pointer.

Enter your choice: 1

Unsorted array: 34 12 25 8 50
Sorted array:   8 12 25 34 50
```
---

## 📊 Comparison Summary

| Algorithm      | Time Complexity (Avg) | Space Complexity | Stable | Type         |
| -------------- | --------------------- | ---------------- | ------ | ------------ |
| Bubble Sort    | O(n²)                 | O(1)             | ✅      | In-place     |
| Selection Sort | O(n²)                 | O(1)             | ❌      | In-place     |
| Insertion Sort | O(n²)                 | O(1)             | ✅      | In-place     |
| Merge Sort     | O(n log n)            | O(n)             | ✅      | Not in-place |
| Quick Sort     | O(n log n)            | O(log n)         | ❌      | In-place     |

