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
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        
        unordered_map<int, vector<int>>graph;
        for(auto &edge: edges) graph[edge[0]].push_back(edge[1]);
        
        vector<int>topo_order;
        vector<int>inDegree(V, 0);
        
        for(int i=0; i<V; i++){
            for(auto neighbour: graph[i]){
                inDegree[neighbour]++; // as i se neighbour ke beech edge hai
            }
        }
        
        queue<int>qu;
        for(int i=0; i<V; i++) if(inDegree[i] == 0) qu.push(i);
        
        while(!qu.empty()){
            
            int node = qu.front();
            topo_order.push_back(node);
            qu.pop();
            
            for(auto neighbour: graph[node]){
                
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) qu.push(neighbour);
            }
        }
        
        return topo_order;
    }
};