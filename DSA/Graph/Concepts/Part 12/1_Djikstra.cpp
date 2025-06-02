/*

Question:
Given an undirected weighted graph along with source and destination. Find the shortest path between the source and destination in term of sum of edge cost.

BFS ko priority queue me chgage karke greedy a;lgorithm lagana --> dijkistra algorithm

*/

#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
#include<list>
#include<unordered_map>
#include<climits>
#include<algorithm>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pair<int,int>>>graph;

void addEdge(int u, int v, int wt, bool biDir = true){
    graph[u].push_back({v,wt}); 
    if(biDir) graph[v].push_back({u,wt});
}

ll minimmumCost(int src, int dest, int n){ // Djikstra Algorithm, ***** O(VlogV + ElogV) *****

    priority_queue<pp, vector<pp>, greater<pp>>pq; // min-heap, {wt,node}
    unordered_set<int>visited;
    vector<int>via(n); // via 'node', we have created vai to trace the path
    unordered_map<int,int>mp; // {node, cost} --> cost --> source se 'node' tak ka minimum distance

    for(int i=0; i<n; i++){ // O(V)
        mp[i] = INT_MAX;
    }

    pq.push({0,src});
    mp[src] = 0;

    while(!pq.empty()){ // TC = TC(for loop/BFS)*TC(line 45-53) ==> O( (V+E)*logV )

        pp curr = pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }

        visited.insert(curr.second);
        pq.pop();

        for(auto neighbour: graph[curr.second]){ // current me node 2nd hai, graph me node 1st hai

            if(!visited.count(neighbour.first) && mp[neighbour.first] > neighbour.second + mp[curr.second]){ // agar map me source se neighbour node ka distance > edge-weight between neighbour and parent + source se parent ka distance 

                pq.push({neighbour.second+mp[curr.second], neighbour.first}); 
                mp[neighbour.first] = neighbour.second+mp[curr.second]; // this is relaxation algorithm, sources se neighbour node ka distance = edge-weight between neighbour and parent + source se parent ka distance 
                via[neighbour.first] = curr.second; // vai parent of the neighbour node
            }
        }
    }

    return mp[dest]; // map me source se har node ka distance store hai

}

int main(){

    int n,e; // number of vertices and edges
    cin>>n>>e; 

    graph.resize(n,list<pair<int,int>>()); // 0 based indexing
    while(e--){

        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt); // bi-directional graph
    }

    int src,dest;
    cin>>src>>dest;

    cout<<minimmumCost(src,dest,n)<<endl;
    return 0;
}