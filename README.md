# cpp
Algorithms and Data Structures in C++

### Graph Algorithms

* [DFS](./graphs/DFS.cpp)
* [BFS](./graphs/BFS.cpp)
* Topological Sort: [Tarjan](./graphs/topological_sort_tarjan.cpp), [Kahn](./graphs/topological_sort/topological_sort_kahn.cpp)
* [Bipartite Check](./graphs/bipartite_check.cpp)
* [All Pairs Shortest Paths (APSP) Floyd-Warshall](./graphs/apsp_floyd_warshall.cpp)
* [Max Flow Edmonds Karp](./graphs/max_flow_edmonds_karp.cpp)

### Tree Algorithms

* [Tree traversal](./trees/tree_traversal.cpp)
* [Tree level order](./trees/tree_level_order.cpp)  
* [Tree vertical order](./trees/tree_vertical_order.cpp)
* [Tree diameter](./trees/tree_diameter.cpp)  
* [Valid BST](./trees/tree_isValidBST.cpp)  
* [Symmetric Tree](./trees/tree_isSymmetric.cpp) 


### Complete Search

* [Generating Subsets](./complete_search/subset_gen.cpp)
* [Eight Queens Problem](./complete_search/eight_queens.cpp)
* [Branch and Bound Knapsack](./complete_search/knapsack_branch_and_bound.cpp)
* [Exact Set Cover](./complete_search/exact_cover.cpp)  

### Greedy Algorithms

* [Interval Schedule](./greedy/interval_schedule/interval_schedule.cpp)  
* [Coin change](./greedy/coin_change_greedy.cpp)  
* Minimum Spanning Tree: [Kruskal](./greedy/mst_kruskal.cpp)   
* [Huffman Coding](./greedy/huffman_coding.cpp)  
* [Fractional Knapsack](./greedy/knapsack_greedy.cpp)  

### Divide and Conquer

* [Binary Search](./divide_and_conquer/binary_search.cpp)  
* [Quick Select](./divide_and_conquer/quick_select.cpp)  

### Dynamic Programming

* [Binomial Coefficients](./dynamic_programming/binomial_coeffs.cpp)  
* [Knapsack](./dynamic_programming/knapsack_dp.cpp)  
* [Coin Change](./dynamic_programming/coin_change.cpp)
* [Max subarray sum](./dynamic_programming/max_subarray_sum.cpp)
* [Memoized Matrix Chain Product](./dynamic_programming/matrix_chain.cpp)
* [Longest Common Substring](./dynamic_programming/longest_common_substring/longest_common_substring.cpp)
* [String Alignment Needleman-Wunsch](./dynamic_programming/string_alignment.cpp)

### Sorting

* [Radix sort](./sorting/radix_sort.cpp)
* [Bucket sort](./sorting/bucket_sort.cpp)
* [Quick sort](./sorting/quick_sort.cpp)
* [Merge sort](./sorting/merge_sort.cpp)
* [Heap sort](./sorting/heap_sort.cpp)
* [Selection sort](./sorting/selection_sort.cpp)  
* [Insertion sort](./sorting/insertion_sort.cpp)  

### Data Structures

* [Trie](./data_structures/trie.cpp)  
* [Binary Heap](./data_structures/binary_heap.cpp)  
* [Circular Queue](./data_structures/circular_queue.cpp)  
* [Queue Using 2 Stacks](./data_structures/queue_with_2stacks.cpp)  
* [Binary Search Tree](./data_structures/bst.cpp)  
* [Disjoint Set Union Find](./data_structures/union_find.cpp) 
 

### Misc

* [Sieve of Eratosthenes](./misc/sieve_of_eratosthenes.cpp)
* [Convex Polygon Check](./misc/is_convex.cpp)
* [Sliding window](./misc/sliding_window.cpp)
* [String matching](./misc/string_matching.cpp)
* [Matrix Spiral](./misc/matrix_spiral.cpp)
* [Two Pointers](./misc/two_pointers.cpp)
* [Intersection](./misc/intersection.cpp)
* [Matching Parenthesis](./misc/matching_parentheses.cpp)
* [Cycle Detection (Floyd)](./misc/cycle_detection_floyd.cpp)
* [Flood Fill](./misc/flood_fill.cpp)  
* [Tower of Hanoi](./misc/tower_of_hanoi.cpp)  
* [Fast Power](./misc/fast_power.cpp)  
* [Connected Components](./misc/connected_components.cpp)    
* [Fisher-Yates shuffle](./misc/fisher_yates_shuffle.cpp)  
* [Generating permutations](./misc/permutations.cpp)  


### Machine Learning

* [KD Tree](./machine_learning/kdtree.cpp)  
* [Alpha Beta Pruning](./machine_learning/alpha_beta_pruning.cpp)  
* [Perceptron](./machine_learning/perceptron/perceptron.cpp)    
* [Dirichlet-Process K-means](./machine_learning/dpmeans/dpmeans.cpp)  
* [Binary Logistic Regression](./machine_learning/logreg/logreg.cpp)  
* [L-BFGS optimization](./machine_learning/lbfgs/lbfgs_simple.cpp)  

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
