# cpp
Algorithms and Data Structures in C++

### Graph Algorithms

* DFS [C++](./graphs/DFS.cpp)
* BFS [C++](./graphs/BFS.cpp)
* Topological Sort (Kahn) [C++](./graphs/topological_sort/topological_sort_kahn.cpp)
* Bipartite Check [C++] (./graphs/bipartite_check.cpp)
* All Pairs Shortest Paths (APSP) Floyd-Warshall [C++](./graphs/apsp_floyd_warshall)
* Max Flow Edmonds Karp [C++](./graphs/max_flow_edmonds_karp.cpp)

### Tree Algorithms

* Tree traversal: [C++](./trees/tree_traversal.cpp)
* Tree vertical order: [C++](./trees/tree_vertical_order.cpp)

### Complete Search

### Greedy Algorithms

* Interval Schedule: [C++](./greedy/interval_schedule/interval_schedule.cpp)  
* Huffman Coding: [C++](./greedy/huffman_coding.cpp)  
* Knapsack: [C++](./greedy/knapsack_greedy.cpp)  

### Divide and Conquer

* Binary Search: [C++](./divide_and_conquer/binary_search.cpp)  

### Dynamic Programming

* Binomial Coefficients: [C++](./dynamic_programming/binomial_coeffs.cpp)  
* Knapsack: [C++](./dynamic_programming/knapsack_dp.cpp)  
* Coin Change: [C++](./dynamic_programming/coin_change.cpp)
* Max subarray sum: [C++](./dynamic_programming/max_subarray_sum.cpp)
* Memoized Matrix Chain Product: [C++](./dynamic_programming/matrix_chain.cpp)
* Longest Common Substring: [C++](./dynamic_programming/longest_common_substring/longest_common_substring.cpp)
* String Alignment Needleman-Wunsch: [C++](./dynamic_programming/string_alignment.cpp)

### Sorting

* Selection sort: [C++](./sorting/selection_sort.cpp)  
* Insertion sort: [C++](./sorting/insertion_sort.cpp)  
* Merge sort: [C++](./sorting/merge_sort.cpp)
* Quick sort: [C++](./sorting/quick_sort.cpp)
* Heap sort: [C++](./sorting/heap_sort.cpp)

### Data Structures

* Disjoint Set Union Find (DSUF) data structure: [C++](./data_structures/union_find.cpp)  

### Misc

* Eight Queens Problem: [C++](./misc/eight_queens.cpp)
* Sieve of Eratosthenes: [C++](./misc/sieve_of_eratosthenes.cpp)
* Convex Polygon Check: [C++](./misc/is_convex.cpp)
* Sliding window: [C++](./misc/sliding_window.cpp)
* String matching: [C++](./misc/string_matching.cpp)

### Machine Learning

* Dirichlet-Process K-means: [C++](./dpmeans/dpmeans.cpp)
* L-BFGS optimization: [C++](./lbfgs/lbfgs_simple.cpp)

### Jupyter Notebooks

The notebooks were created using [xeus-cling](https://github.com/QuantStack/xeus-cling): a Jupyter kernel for C++

* xtensor: [ipynb](https://github.com/vsmolyakov/cpp/blob/master/notebooks/xtensor.ipynb)
* eigen: [ipynb](https://github.com/vsmolyakov/cpp/blob/master/notebooks/eigen.ipynb)


### Compiling

To compile the C++ files, run the following command:

```
g++ <filename.cpp> --std=c++11 -Wall -o test 
```

### Dependencies

C++11
