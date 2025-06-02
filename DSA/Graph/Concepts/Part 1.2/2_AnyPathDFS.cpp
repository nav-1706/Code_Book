// TC: O(V+E) --> Worst case me har edge par jaana hai, then har vertex par
// SC = O(V), coz of recursion

// To check if theres is any path exist between given sourve and destination

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>>graph;
unordered_set<int>visited;

int v; // number of vertices

// add edge function
void addEdge(int src, int dest, bool biDir=true){

    graph[src].push_back(dest); // list me push_back kiya hai
    if(biDir){
        graph[dest].push_back(src); // agar bi directional hai to dest me bhi push
    }
}

bool dfs(int curr, int end){

    if(curr == end) return true;
    visited.insert(curr); // current node marked visited

    for(auto neighbour: graph[curr]){
        if(!visited.count(neighbour)){ // visited nahi hai tabhi call maarenge
            bool result = dfs(neighbour,end);
            if(result == true) return true;
        }
    }

    return false;
}

bool anyPath(int src, int dest){

    return dfs(src, dest);
}

int main(){

    // graph input 
    cout<<"Enter the number of vertices"<<endl;
    cin>>v;
    graph.resize(v, list<int>());

    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    visited.clear();

    while(e--){

        int s,d;
        cout<<"Enter source vertex"<<endl;
        cin>>s;

        cout<<"Enter destination vertex"<<endl;
        cin>>d;

        addEdge(s,d); // for directed graph just add false in agrument

    }


    return 0;
}