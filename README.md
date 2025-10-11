# Algorithms Repository

A comprehensive collection of classic algorithms implemented in both **C++** and **Python**. This repository covers sorting, graph algorithms, dynamic programming, backtracking, and string matching techniques.

## 🔤 Sorting Algorithms

### 1. **Insertion Sort**
Builds the sorted array one item at a time by inserting elements into their correct position.
- **Time Complexity:** O(n²) average/worst case, O(n) best case
- **Space Complexity:** O(1)
- **Files:** `cpp/insertionsort.cpp`, `python/insertionsort.py`

### 2. **Selection Sort**
Repeatedly finds the minimum element and places it at the beginning.
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)
- **Files:** `cpp/selection_sort.cpp`, `python/selectionsort.py`

### 3. **Merge Sort**
Divide-and-conquer algorithm that divides the array in half and merges sorted subarrays.
- **Time Complexity:** O(n log n) all cases
- **Space Complexity:** O(n)
- **Files:** `cpp/mergesort.cpp`, `python/mergesort.py`

### 4. **Quick Sort**
Divide-and-conquer algorithm using a pivot element for partitioning.
- **Time Complexity:** O(n log n) average, O(n²) worst case
- **Space Complexity:** O(log n) average
- **Files:** `cpp/quicksort.cpp`, `python/quicksort.py`

---

## 📊 Graph Algorithms

### 1. **BFS & DFS**
Breadth-First Search and Depth-First Search for graph traversal.
- **BFS Time Complexity:** O(V + E)
- **DFS Time Complexity:** O(V + E)
- **Files:** `cpp/bfsdfs.cpp`, `python/bfsdfs.py`

### 2. **Dijkstra's Algorithm**
Finds shortest paths from a source vertex to all other vertices in a weighted graph.
- **Time Complexity:** O((V + E) log V) with priority queue
- **Space Complexity:** O(V)
- **Files:** `cpp/dikstra.cpp`, `python/dikstra.py`

### 3. **Floyd-Warshall Algorithm**
Finds shortest paths between all pairs of vertices.
- **Time Complexity:** O(V³)
- **Space Complexity:** O(V²)
- **Files:** `cpp/floyd_warshall.cpp`, `python/flody.walrsl.py`

### 4. **Kruskal's Algorithm**
Finds the Minimum Spanning Tree using a greedy approach with Union-Find.
- **Time Complexity:** O(E log E)
- **Space Complexity:** O(V)
- **Files:** `cpp/kruskal.cpp`, `python/kruskal.py`

### 5. **Prim's Algorithm**
Finds the Minimum Spanning Tree by growing the tree from a starting vertex.
- **Time Complexity:** O((V + E) log V) with priority queue
- **Space Complexity:** O(V)
- **Files:** `cpp/prims.cpp`, `python/prims.py`

---

## 💾 Dynamic Programming

### 1. **0/1 Knapsack Problem**
Solves the classic knapsack problem with capacity constraints and item selection tracking.
- **Time Complexity:** O(n × W) where W is capacity
- **Space Complexity:** O(n × W)
- **Features:** Shows DP table and selected items
- **Files:** `cpp/01knapsack.cpp`, `python/01knapsack.py`

### 2. **Longest Common Subsequence (LCS)**
Finds the longest subsequence common to two sequences.
- **Time Complexity:** O(m × n)
- **Space Complexity:** O(m × n)
- **Features:** Displays both DP and direction tables
- **Files:** `cpp/LCS.cpp`, `python/lcs.py`

---

## 🔙 Backtracking Algorithms

### 1. **N-Queens Problem**
Solves the N-Queens puzzle where N queens must be placed on an N×N chessboard such that no two queens threaten each other.
- **Time Complexity:** O(N!) worst case
- **Space Complexity:** O(N)
- **Features:** Displays all solutions with board visualization
- **Files:** `cpp/Nqeen.cpp`, `python/Nqeen.py`

### 2. **Sum of Subsets**
Finds all subsets of a given set that sum to a target value.
- **Time Complexity:** O(2ⁿ)
- **Space Complexity:** O(n)
- **Features:** Shows subset elements and binary representation
- **Files:** `cpp/sumofsub.cpp`, `python/sumofsub.py`

---

## 🔍 String Matching

### **Rabin-Karp Algorithm**
Uses hashing to find pattern occurrences in text efficiently.
- **Time Complexity:** O(n + m) average case
- **Space Complexity:** O(1)
- **Features:** Handles multiple pattern occurrences
- **Files:** `cpp/rabin_karp.cpp`, `python/rabin_karp.py`

---

## 📝 Algorithm Categories

| Category | Count | Algorithms |
|----------|-------|-----------|
| Sorting | 4 | Insertion, Selection, Merge, Quick |
| Graph | 5 | BFS/DFS, Dijkstra, Floyd-Warshall, Kruskal, Prim |
| Dynamic Programming | 2 | 0/1 Knapsack, LCS |
| Backtracking | 2 | N-Queens, Sum of Subsets |
| String Matching | 1 | Rabin-Karp |

---

## 🤝 Contributing

Feel free to improve these implementations or add new algorithms!

---

## 📄 License

This repository is open for educational purposes.

---


Happy Learning! 🎓
