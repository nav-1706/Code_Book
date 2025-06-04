// Topological Sort --> Exists in Directed Acyclic Graph (DAG) --> Multiple topolocial sort is possible in a graph

// https://youtu.be/WbbYZRr4arw?si=kD1qSxFMraOzpGKR

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
  
    void topoDFS(int curr, unordered_map<int, vector<int>>&graph, vector<int>&visited, vector<int>&ans){
        
        visited[curr] = true;
        
        for(int neighbour: graph[curr]){
            
            if(visited[neighbour] == false){
                
                topoDFS(neighbour, graph, visited, ans);
            }
        }
        
        ans.push_back(curr);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<int>visited(V, false);
        
        unordered_map<int, vector<int>>graph;
        for(auto &edge: edges) graph[edge[0]].push_back(edge[1]);
        
        vector<int>ans;
        
        for(int i=0; i<V; i++){
            
            if(visited[i] == false) topoDFS(i, graph, visited, ans);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};