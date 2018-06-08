# cpp
Algorithms and Data Structures in C++

### Graph Algorithms

* [DFS](./graphs/DFS.cpp)
* [BFS](./graphs/BFS.cpp)
* [Topological Sort (Kahn)](./graphs/topological_sort/topological_sort_kahn.cpp)
* [Bipartite Check](./graphs/bipartite_check.cpp)
* [All Pairs Shortest Paths (APSP) Floyd-Warshall](./graphs/apsp_floyd_warshall.cpp)
* [Max Flow Edmonds Karp](./graphs/max_flow_edmonds_karp.cpp)

### Tree Algorithms

* [Tree traversal](./trees/tree_traversal.cpp)
* [Tree vertical order](./trees/tree_vertical_order.cpp)

### Complete Search

### Greedy Algorithms

* [Interval Schedule](./greedy/interval_schedule/interval_schedule.cpp)  
* [Huffman Coding](./greedy/huffman_coding.cpp)  
* [Knapsack](./greedy/knapsack_greedy.cpp)  

### Divide and Conquer

* [Binary Search](./divide_and_conquer/binary_search.cpp)  

### Dynamic Programming

* [Binomial Coefficients](./dynamic_programming/binomial_coeffs.cpp)  
* [Knapsack](./dynamic_programming/knapsack_dp.cpp)  
* [Coin Change](./dynamic_programming/coin_change.cpp)
* [Max subarray sum](./dynamic_programming/max_subarray_sum.cpp)
* [Memoized Matrix Chain Product](./dynamic_programming/matrix_chain.cpp)
* [Longest Common Substring](./dynamic_programming/longest_common_substring/longest_common_substring.cpp)
* [String Alignment Needleman-Wunsch](./dynamic_programming/string_alignment.cpp)

### Sorting

* [Heap sort](./sorting/heap_sort.cpp)
* [Quick sort](./sorting/quick_sort.cpp)
* [Merge sort](./sorting/merge_sort.cpp)
* [Selection sort](./sorting/selection_sort.cpp)  
* [Insertion sort](./sorting/insertion_sort.cpp)  

### Data Structures

* [Disjoint Set Union Find (DSUF) data structure](./data_structures/union_find.cpp)  

### Misc

* [Eight Queens Problem](./misc/eight_queens.cpp)
* [Sieve of Eratosthenes](./misc/sieve_of_eratosthenes.cpp)
* [Convex Polygon Check](./misc/is_convex.cpp)
* [Sliding window](./misc/sliding_window.cpp)
* [String matching](./misc/string_matching.cpp)

### Machine Learning

* [Dirichlet-Process K-means](./dpmeans/dpmeans.cpp)
* [L-BFGS optimization](./lbfgs/lbfgs_simple.cpp)

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
