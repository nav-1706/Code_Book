/*
Algorithm:
    1. If we are performing DFS on a node, and encounter that its neighbour node is already visited and not his parent, then the graph has cycle


Similary can be done with BFS, for this we can create a parent vector for every node
*/

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>>graph; // Graph representation
unordered_set<int>visited; // Set to track visited nodes
vector<vector<int>>result; // Vector to store all paths

int v; // number of vertices

// add edge function
void addEdge(int src, int dest, bool biDir=true){

    graph[src].push_back(dest); // list me push_back kiya hai
    if(biDir){
        graph[dest].push_back(src); // agar bi directional hai to dest me bhi push
    }
}

bool dfs(int src, int parent, unordered_set<int>&visited){
    
    visited.insert(src); // visited me add kiya hai
    for(auto neighbour: graph[src]){

        if(neighbour == parent) continue; // agar parent hai to skip
        if(visited.find(neighbour) != visited.end() && parent!=neighbour){ // visited hai and it is not parent
            return true; // cycle detected
        }

        if(visited.find(neighbour) == visited.end() ){ // if not visited
            return dfs(neighbour,src,visited);
        }
    }

    return false;
}

bool has_cycle(){

    unordered_set<int>visited;
    bool result;
    for(int i=0; i<v; i++){ // coz the graph can be disconnected
        if(visited.find(i) == visited.end() ){ // not visited, matlab koi parent nahi hai inka
            return result = dfs(i,-1,visited);
        }
    }

    return false;
}       

int main(){

    // graph input 
    //cout<<"Enter the number of vertices"<<endl;
    cin>>v;
    graph.resize(v, list<int>());

    int e;
    //cout<<"Enter the number of edges"<<endl;
    cin>>e;
    visited.clear();

    while(e--){

        int s,d;
        //cout<<"Enter source vertex"<<endl;
        //cin>>s;

        //cout<<"Enter destination vertex"<<endl;
        //cin>>d;

        cin>>s>>d;

        addEdge(s,d); // for directed graph just add false in agrument

    }


    return 0;
}