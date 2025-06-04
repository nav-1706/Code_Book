// https://youtu.be/K_LamGUvwUc?si=iiOm_AW6YCIfkvj8

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
  
    bool isCycleDFS(int curr, vector<int>&visited, vector<int>&inRec, unordered_map<int, vector<int>>&graph){
        
        visited[curr] = true;
        inRec[curr] = true;
        
        for(int neighbour: graph[curr]){
            
            if(visited[neighbour] == false){
                
                bool result = isCycleDFS(neighbour, visited, inRec, graph);
                if(result) return true;
            }
            
            else{ // visited[neighbour] == true;
                
                if(inRec[neighbour] == true) return true;
            }
        }
        
        inRec[curr] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<int>visited(V, false);
        vector<int>inRec(V, false);
        
        unordered_map<int, vector<int>>graph;
        for(auto &edge: edges){
            
            graph[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0; i<V; i++){
            
            if(visited[i] == false) if(isCycleDFS(i, visited, inRec, graph) == true) return true;
        }
        
        return false;
    }
};