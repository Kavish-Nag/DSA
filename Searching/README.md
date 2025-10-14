# 🔍 Searching Algorithms in C

This program demonstrates two fundamental **searching algorithms** — **Linear Search** and **Binary Search** — implemented in C.  
It allows users to input a list of elements and interactively choose which search method to apply.

---

## ⚙️ Algorithms Covered

### 🔹 1. Linear Search
- **Logic:**  
  Scans each element of the array one by one until the desired element is found or the end of the array is reached.
- **Steps:**
  1. Start from the first element.  
  2. Compare each element with the search key.  
  3. If a match is found, return its index; otherwise, move to the next element.  
  4. If the loop completes, the element is not present.
- **Complexity:**  
  - Best Case: *O(1)* (if the element is the first one)  
  - Worst Case: *O(n)* (if the element is at the end or absent)  
- **Type:** Sequential Search, works on *unsorted arrays*  
- **Advantage:** Simple and effective for small datasets  
- **Disadvantage:** Inefficient for large datasets

---

### 🔹 2. Binary Search
- **Logic:**  
  Works on the **divide and conquer** principle. The array must be **sorted** beforehand.  
  It repeatedly divides the search interval in half:
  1. Compare the middle element with the target value.  
  2. If equal, return the index.  
  3. If the target is smaller, search the left half; if larger, search the right half.  
- **Complexity:**  
  - Best Case: *O(1)*  
  - Average/Worst Case: *O(log n)*  
- **Type:** Divide and Conquer, works on *sorted arrays only*  
- **Advantage:** Extremely efficient for large, sorted datasets  
- **Disadvantage:** Fails on unsorted data

---

## 🧮 Features

- Menu-based program with easy user interaction  
- Allows user to input a custom array  
- Lets you choose between **Linear** and **Binary Search**  
- Displays clear results with element index or “not found” message  
- Option to **run multiple searches** without restarting the program  

---

## 💻 How to Run

### 🛠 Prerequisites
- GCC compiler installed on your system

### 🧾 Steps
```bash
# Navigate to the folder
cd DSA/Searching

# Compile the program
gcc Search.c -o search

# Run the executable
./search
````

---

## 🧠 Example Output

```
Enter number of elements: 5
Enter element 1: 10
Enter element 2: 25
Enter element 3: 30
Enter element 4: 45
Enter element 5: 50

Enter an element to search: 30
Which way to search?
1. Linear Search.
2. Binary Search.
Enter choice (1/2): 2

Element at index 2
Do you want to continue? (y/n): y
```

---

## 📊 Comparison Summary

| Algorithm     | Works On          | Time Complexity (Avg) | Space Complexity | Requires Sorting | Suitable For   |
| ------------- | ----------------- | --------------------- | ---------------- | ---------------- | -------------- |
| Linear Search | Unsorted / Sorted | O(n)                  | O(1)             | ❌                | Small datasets |
| Binary Search | Sorted only       | O(log n)              | O(1)             | ✅                | Large datasets |

---

