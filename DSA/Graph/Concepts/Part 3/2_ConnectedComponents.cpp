// TC: O(V+E) // same question but in other graph implementation --> LEETCODE 547

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>>graph; // Graph representation

int v; // number of vertices

// add edge function
void addEdge(int src, int dest, bool biDir=true){

    graph[src].push_back(dest); // list me push_back kiya hai
    if(biDir){
        graph[dest].push_back(src); // agar bi directional hai to dest me bhi push
    }
}

void dfs(int node, unordered_set<int>&visited){

    visited.insert(node);
    for(auto neighbour: graph[node]){
        if(!visited.count(neighbour)){

            dfs(neighbour,visited);
        }
    }
}

int connectedComponent(){

    int result = 0;
    unordered_set<int>visited; // visited is passed by reference

    for(int i=0; i<v; i++){ // go to every node

        if(visited.count(i) == 0){
            result++; // jitni baar dfs(not taking about resursive calls in dfs) hoga utne connected component
            dfs(i,visited);
        }
    }

    return result;
}

int main(){

    // graph input 
    //cout<<"Enter the number of vertices"<<endl;
    cin>>v;
    graph.resize(v, list<int>());

    int e;
    //cout<<"Enter the number of edges"<<endl;
    cin>>e;

    while(e--){

        int s,d;
        //cout<<"Enter source vertex"<<endl;
        //cin>>s;

        //cout<<"Enter destination vertex"<<endl;
        //cin>>d;

        cin>>s>>d;

        addEdge(s,d); // for directed graph just add false in agrument

    }

    cout<<"Number of connected graph: "<<connectedComponent()<<endl;

    
    return 0;
}