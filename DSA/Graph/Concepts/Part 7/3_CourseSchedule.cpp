// LEETCODE 207
/*

This question is of dependency resolution, for dependency resolution the graph must be directed and acyclic (DAG)

Cyclic graph can't be solved for dependency resolutiuon

Google: n equalities are given, can these inequalities can be resolved ?--> this is dependency resolution problem

For dependency resolution, we use topological sort(kahn's algorithm)

Kahn's algorithm:

    1. Make an array of in-degree

    2. Kind of use multi-source BFS, make a queue and put nodes whose indegrre is 0

    3. For example in given graph in 3.2 0 and 1 has 0 indegree, we have inserted 0 and 1 in the queue, 

    4. If we process 0, we will pop it from the queue, and 0 ke jitne bhi neighbours hai, unka in-degree array me se ek value kam ho jaaegi, as unki ek dependency(i.e. 0) process/complete ho chuki hai.

*/