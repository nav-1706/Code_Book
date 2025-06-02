// NOTE: NO NEED TO MAINTAIN THE VISITED ARRAY AS WE ARE ALREADY MAINTAING THE INDEGREE ARRAY

// APPLICAPLE ONLY TO DIRECTED ACYCLIC GRAPH

// NOTE: TOPOLOGICAL SORT AISI NODES DETA HAI JO CYCLE ME PARTICIPATE NAHI KAR RAHI


#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>

using namespace std;

vector<list<int>>graph;
int v; // numbe of verteices

void addEdge(int a, int b, bool biDir = true){

    graph[a].push_back(b);
    if(biDir) graph[b].push_back(a);
}

void topoBFS(){ // Kahn's Algorithm

    vector<int>inDegree(v, 0); // initially sabki indegree 0 rakh di, baad me increase karenge

    for(int i=0; i<v; i++){

        for(auto neighbour: graph[i]){
            inDegree[neighbour]++; // as i se neighbour ke beech edge hai
        }
    }

    queue<int>qu;
    unordered_set<int>visited;

    for(int i=0; i<inDegree.size(); i++){
        if(inDegree[i] == 0){
            qu.push(i);
            visited.insert(i);
        }
    }

    while(!qu.empty()){

        int node = qu.front(); // node processed
        cout<<node<<" ";
        qu.pop();
        for(auto neighbour: graph[node]){

            if(!visited.count(neighbour)){
                inDegree[neighbour]--; // as ispar aane wale edge("node" se) process ho gayi
                if(inDegree[neighbour] == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }

}

int main(){

    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());    

    while(e--){
        int x,y;
        cin>>x>>y;
        addEdge(x,y,false);
    }

    topoBFS();
    // If the graph is not DAG, we will not get visited as the size of number of vertcies

    return 0;
}
