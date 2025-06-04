// https://youtu.be/0X0lEtTkk-8?si=_Pygnu_qVcwN9wUU

// With DSU we can only find loop in Un-Directed graph

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    
    vector<int>parent;
    vector<int>Rank;
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
    
        int x_parent = find(x);
        int y_parent = find(y);
    
        if(Rank[x_parent] > Rank[y_parent]){
    
            parent[y_parent] = x_parent;
        }
    
        else if(Rank[x_parent] < Rank[y_parent]){
    
            parent[x_parent] = y_parent;
        }
    
        else{
    
            parent[y_parent] = x_parent;
            Rank[x_parent]++;
        }
    }

    
    int detectCycle(int V, vector<int> adj[]) {
        
        Rank.resize(V,0);
        parent.resize(V);
        for(int i=0; i<V; i++) parent[i] = i;
        
        for(int u=0; u<V; u++){
            
            for(auto &v: adj[u]){
                
                if(u < v){ // because if in undirected graph, if we have cheacked edge 1-->2, we don't have to check for 2-->1, otherwuise it will return true for loop presence
                     
                    int parent_u = find(u);
                    int parent_v = find(v);
                    
                    if(parent_u == parent_v) return true;
                    Union(u, v);
                }
            }
        }
        
        return false;
    }
};