/*
---------------------------------------------------------
For undirected(bidirectional) and unweighted graph
---------------------------------------------------------

In this representation we represent graph as a array of linked list

ith index of the array stores/represents the neighbour of ith vertex(directly connected).
for example: in 3rd index, a linked list will be present containg 2nd and 6th vertex
Size of array == number of vertices

neighbour: any vertex having direct edge from a vertex

--------------------------------------------------------
For directed and unweighted graph
--------------------------------------------------------

In this representation we represent graph as a array of linked list

ith index of the array stores/represents the approachable neighbour of ith vertex.
for example: in 3rd index, a linked list will be present, containg 2nd vertex only

---------------------------------------------------------
For directed weighted graph && undirected weighted graph
---------------------------------------------------------

vector<list<pair<int,int>>>>graph
graph.push_back({1,6});

In this representation we represent graph as a array of linked list

ith index of the array stores/represents the approachable neighbour of ith vertex.

In the linked list instead of just storing the neighbour vertex, we will also store the weight in the pair form (neighbour vertex, weight)

It is the most used implementation

*/