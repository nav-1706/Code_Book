/*

If number of edges <= number of vertices (sparse garph) --> we wil prefer Krushkal's algorithm, as we have to perform sort operation on edges.

If number of edges >> number of vertices(dense graph) --> we will prefer Prim's algorithm as it is dependent on vertices, not edges.

In gereral prefer Kruhkal's, as it is easy to implement.

- If in Djikistra, all weights are equal, use normal BFS and then multiply the final answer with the weight.

- If in Djikstra, weights are given in binary format, (i.e 0,1 or 0,x), slove by 0-1 BFS(asked in google)

In 0-1 BFS, we implement deque, instead of normal queue and pust '0' wight at front, and '1' weight at back

*/