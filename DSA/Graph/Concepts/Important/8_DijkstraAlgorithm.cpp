/*

| Graph Type                          | Allowed in Dijkstra? | Notes                                                           |
| ----------------------------------- | -------------------- | --------------------------------------------------------------- |
| **Directed Graph**                  | ✅ Yes                | Works if all edge weights are **non-negative**.                 |
| **Undirected Graph**                | ✅ Yes                | Add edges in both directions; weights must be **non-negative**. |
| **Directed Acyclic Graph (DAG)**    | ✅ Yes                | Works, but **topological sort + DP** is often faster for DAGs.  |
| **Directed Cyclic Graph**           | ✅ Yes                | Cycles allowed **only if no negative weight edges**.            |
| **Undirected Acyclic Graph (Tree)** | ✅ Yes                | Trivially works — no cycles; efficient.                         |
| **Undirected Cyclic Graph**         | ✅ Yes                | Cycles are fine as long as weights are non-negative.            |
| **Self-loops (e.g., `u–u`)**        | ✅ Yes                | Usually don’t affect shortest paths unless weighted unusually.  |
| **Negative-weight edges**           | ❌ No                 | Use **Bellman-Ford** for such cases.                            |
| **Negative-weight cycles**          | ❌ No                 | Dijkstra **does not detect** or handle them correctly.          |
| **Disconnected graph components**   | ✅ Yes                | Returns `INT_MAX` for unreachable nodes.                        |


*/

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
  public:
  
    typedef pair<int,int> P;
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        unordered_map<int, vector<pair<int,int>>>graph; // {node, {neighbour, edge_wt}}
        for(auto &edge: edges){
            
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<int>dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src}); // {dist from source, node}
        
        while(!pq.empty()){
            
            int dist_of_node_from_src = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &neighbourPair: graph[node]){
                
                int neighbourNode = neighbourPair.first;
                int edge_wt_from_node_to_neighbour = neighbourPair.second;
                
                if(dist_of_node_from_src + edge_wt_from_node_to_neighbour < dist[neighbourNode]){
                    
                    dist[neighbourNode] = dist_of_node_from_src + edge_wt_from_node_to_neighbour;
                    pq.push({dist_of_node_from_src + edge_wt_from_node_to_neighbour, neighbourNode});
                }
            }
        }
        
        return dist;
    }
};