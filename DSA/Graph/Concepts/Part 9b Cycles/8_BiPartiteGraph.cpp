/* If a graph is bipartite then it has no odd cycles conversly a graph is bipartite if any only if it has odd length cycles

All graph are bi-partite except the odd-length graph
Keywords: dividing and grouping in 2 parts
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    bool dfs(int curr, int curr_color, vector<vector<int>>& graph, vector<int>&color){

        color[curr] = curr_color;

        for(auto neighbour: graph[curr]){
            if(color[neighbour] == curr_color) return false; // not bi-partite
            else if(color[neighbour] == -1){ // not visited, never colored before
                if(dfs(neighbour, 1-curr_color, graph, color) == false) return false;
            }
        }

        return true;
    }

    bool isBi(int v, vector<vector<int>>& graph, vector<int>&color){

        for(int i = 0; i<v; i++){
            if(color[i] == -1){
                if(dfs(i, 1, graph, color) == false) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color;
        int v = graph.size();
        color.resize(v, -1); // it will also works as visited array

        return isBi(v, graph, color);
    }
};