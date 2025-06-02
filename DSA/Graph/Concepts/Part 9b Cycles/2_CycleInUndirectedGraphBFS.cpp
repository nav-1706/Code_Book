// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<vector>
#include<iostream>
#include<queue>
using namespace std;


class Solution {
  public:
    
    bool cycleBFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> qu; // {node, parent}
        qu.push({start, -1});
        visited[start] = true; // Mark as visited when added to the queue

        while (!qu.empty()) {
            int curr = qu.front().first;
            int parent = qu.front().second;
            qu.pop();

            for (auto neighbour : adj[curr]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true; // Mark as visited
                    qu.push({neighbour, curr});
                } else if (neighbour != parent) {
                    // If visited and not the parent, a cycle exists
                    return true;
                }
            }
        }

        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<bool>visited(n, false);
        
        for(int i = 0; i<n; i++){
            if(visited[i] == false){
        
                if(cycleBFS(i, adj, visited)) return true;
            }
        }
        
        return false;
    }
};