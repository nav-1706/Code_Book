// This algo will work fine if one connected component has only one cycle

#include<iostream>
#include<vector>
using namespace std;

vector<bool>visited;
vector<int>Count;
vector<int>ans;

void dfs(int node, int parent, vector<vector<int>>&graph){

    visited[node] = true;

    for(auto neighbour: graph[node]){
        if(visited[neighbour] == false){
            Count[neighbour] = Count[node] + 1;
            dfs(neighbour, node, graph);
        }

        else{
            if(neighbour != parent){ // cycle mil gaya
                if(Count[node]-Count[neighbour] > 0) ans.push_back(Count[node]-Count[neighbour]+1);
            }
        }
    }
}

void cycle_len(int v ,vector<vector<int>>&graph){

    for(int i = 0; i<v; i++){
        if(visited[i] == false){
            dfs(i, -1, graph);
        }
    }
}

int main(){

    vector<vector<int>> graph = {
        {1, 6},       
    {0, 2},       
    {1, 3},       
    {2, 4},           
    {3, 5},           
    {4, 6},           
    {0, 5},                    
    };

    int v = graph.size();
    visited.resize(v, false);
    Count.resize(v, 0);

    cycle_len(v, graph);

    for(auto ele: ans) cout<<ele<<" ";
}