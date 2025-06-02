/*

Minimum spanning tree can be find using two greedy algorithm, "kruskals" and "Prims"

Follow Krushkal whenever you can as it is easy to implement

--------------------------------------------
Krushkal's Algorithm(undirected graph):
--------------------------------------------

One by one keep picking edges with minimum weight possible, if choosing an edge forms a cycle avoid it, else use it.

Implementation(standard and efficient):
1. we will sort given edgeList on the basis of weight
2. we will use a disjoint set (DSU) data structure to check if adding an edge will form a cycle

*/