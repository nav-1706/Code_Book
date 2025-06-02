// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<vector>
#include<iostream>
using namespace std;

class Solution {
  public:
    
    vector<int>visited;
    
    bool dfs(int node, int parent, vector<vector<int>>& adj){
        
        visited[node] = true;
        
        for(int neighbour: adj[node]){
            
            if(visited[neighbour] == false){
                if(dfs(neighbour, node, adj)) return true;
            }
            
            else{
                if(neighbour != parent){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool cycle(int v, vector<vector<int>>& adj){
        
        for(int i = 0; i<v; i++){
            if(visited[i] == false){
                if(dfs(i, -1, adj)) return true;;
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        
        int v = adj.size();
        visited.resize(v, false);
        
        return cycle(v, adj);
    }
};