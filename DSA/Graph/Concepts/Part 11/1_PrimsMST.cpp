/*

Implemetation of Prim's is bit complex as compare to Krushkal's
It is also a greedy algorithm (greedy+BFS)
We have to use priority queue to implement this
In prims we start with a source node and try to discover other node

suppose we discover a node 'x', with edge,weight {e1,w1}
and after some steps in BFS, again find 'x' with {e2,w2} and w2<w1, then we will update the discovery of 'x' with {e2,w2}

At the start of algorithm, discovery weight of every node  except sources is infinity as we have not discoved any node

We will use a priority queue(min-heap), and maintain pair of <weight,vertex>

*/
