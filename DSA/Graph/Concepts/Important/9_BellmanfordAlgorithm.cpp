/*

Works only for directed graph, for undirected graph change it to two direcred edges

Works with negative edges and negative cycles, also detects negative cycle

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
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int>dist(V, INT_MAX);
        dist[src] = 0;
        
        for(int count = 1; count <= V-1; count++){
            
            for(auto &edge: edges){
                
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // Now detecting negative cycle --> agar ek baar aur relax ho gaya matlab negative cycle hai
        
        for(auto &edge: edges){
                
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                
                return {-1};
            }
        }
        
        return dist;
    }
};
