// TC: O(V+E)

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

// DFS function to find all paths from curr to end
void dfs(int curr, int end, vector<int>&path){

    visited.insert(curr); // current node marked visited
    path.push_back(curr);

    if(curr == end){
        result.push_back(path); // path ko result me push
    }

    for(auto neighbour: graph[curr]){
        if(!visited.count(neighbour)){ // agar visit nahi kiya to
            dfs(neighbour,end,path); // Recursive call to dfs
        }
    }

    path.pop_back(); // Backtrack to the previous node
    visited.erase(curr); // Unmark current node as visited for other paths

}

void allPath(int src, int dest){

    vector<int>v;
    dfs(src, dest,v);
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

    int x, y;
    cin>>x>>y;
    allPath(x,y);

    for(auto path: result){

        for(auto ele: path){
            cout<<ele<<" --> ";
        }
        cout<<endl;
    }
    return 0;
}