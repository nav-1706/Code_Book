// TC: O(V+E) // same question but in other graph implementation --> LEETCODE 547

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>>graph; // Graph representation
vector<bool>visited;

int v; // number of vertices

// add edge function
void addEdge(int src, int dest, bool biDir=true){

    graph[src].push_back(dest); // list me push_back kiya hai
    if(biDir){
        graph[dest].push_back(src); // agar bi directional hai to dest me bhi push
    }
}

void dfs(int node){

    if(visited[node]) return;

    visited[node] = true;
    for(auto neighbour: graph[node]){
        if(visited[neighbour] == true) continue;
        dfs(neighbour);
    }
}

int connectedComponent(){

    int count = 0;
    for(int i = 0; i<v; i++){
        
        if(visited[i] == false){
            dfs(i);
            count++;
        }
    }

    return count;
}

int main(){

    // graph input 
    cout<<"Enter the number of vertices"<<endl;
    cin>>v;
    graph.resize(v, list<int>());
    visited.resize(v, false);

    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    while(e--){

        int s,d;
        cout<<"Enter source and destination vertex"<<endl;
        // cin>>s;

        // cout<<"Enter destination vertex"<<endl;
        // cin>>d;

        cin>>s>>d;

        addEdge(s,d); // for directed graph just add false in agrument

    } 

    cout<<"Number of connected graph: "<<connectedComponent()<<endl;

    
    return 0;
}