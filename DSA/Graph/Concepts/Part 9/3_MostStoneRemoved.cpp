// LEETCODE 947 --> Not Solved

/*
Algorithm:
    1. When we traverse a graph using DFS, we get a DFS tree, and in a tree(n nodes) we can delete (n-1) nodes, as lower level nodes are dependent on upper level nodes, only the root node can't be deleted

    Hence maximum number of stones removed = Total Nodes - (1*no. of connected components)

*/

// Big Question: How to find number of connected components using DSU