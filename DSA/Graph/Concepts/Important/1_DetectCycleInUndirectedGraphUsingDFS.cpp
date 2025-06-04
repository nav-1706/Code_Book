// https://youtu.be/UrQv5YMC060?si=S3XiM9pgJn1oAQjd

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
  
    unordered_set<int>visited;
    
    bool cycle_dfs(int curr, int parent, unordered_map<int, vector<int>>&graph){
        
        // if(visited.count(curr) != 0) return true;
        visited.insert(curr);
        
        for(auto neighbour: graph[curr]){
            
            if(neighbour != parent){
                
                if(visited.count(neighbour) != 0) return true;
                
                bool result = cycle_dfs(neighbour, curr, graph);
                if(result == true) return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        
        unordered_map<int, vector<int>>graph;
        for(auto &edge: edges){
            
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int i=0; i<V; i++){
            
            if(visited.count(i) == 0) if(cycle_dfs(i, -1, graph)) return true;
        }
        
        return false;
    }
};