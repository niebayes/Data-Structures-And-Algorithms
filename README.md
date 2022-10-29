# Data-Structures-And-Algorithms
My implementation for basic data structures and algorithms

## Data Structures

### Linear data structures
- [x] fixed-size array
- [x] dynamic array
- [x] singly linked list
- [x] doubly linked list
- [x] stack 
- [x] queue
- [x] double-ended queue (deque)
- [x] circular buffer
- [x] bitmap
- [x] monotonic stack
- [x] monotonic queue
- [ ] skiplist
- [x] block array

### Tree-based data structures
- [x] binary tree
- [x] binary search tree
- [x] AVL tree
- [x] binary heap
- [x] union-find (disjoint set)
- [x] trie (prefix tree)
- [x] Fenwick tree (binary indexed tree)
- [x] B+ tree
- [ ] LSM tree 

### Hash-based data structures
- [x] separate chaining hash table
- [ ] open addressing hash table
  - [x] linear probing
  - [x] quadratic probing
  - [ ] double hashing
  - [ ] cuckoo hashing
  - [ ] robin hood hashing
  - [x] extendible hashing
- [ ] bloom filter

### Graph-based data structures
- [x] adjacency list based graph
- [x] adjacency matrix based graph


## Algorithms

### Graph algorithms
- [x] Graph Traversal
  - [x] DFS
  - [x] BFS
- [x] cycle detection for directed graph
  - [x] DFS to detect back edge
  - topological sorting (Kahn) to check if #visited vertices == #vertices
- [x] cycle detection for undirected graph
  - [x] DFS to detect back edge
  - [x] union-find to iterate all edges
- [x] connected components of undirected graph (CC)
  - [x] DFS
  - [x] union-find
- [x] strongly connected components of directed graph (SCC)
  - [x] Kosaraju
- [x] topological sorting 
  - [x] DFS 
  - [x] BFS (Kahn)
- [x] minimum/maximum Spanning Tree (MST)
  - [x] Kruskal
  - [x] Prim
- [x] single source shortest path & source sink shortest path (SSSP)
  - [x] BFS for unweighted graph or graph with uniform-weighted edges
  - [x] Dijkstra for non-negative weighted graph
  - [x] Bellman-Ford for weighted graph
- [x] all pairs shortest path (APSP)
  - [x] Floyd-Warshall
- [x] bipartile graph check
  - [x] alternated two coloring
