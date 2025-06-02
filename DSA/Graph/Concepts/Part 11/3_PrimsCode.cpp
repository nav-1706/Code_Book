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

ll prims(int src, int n){

    priority_queue<pp, vector<pp>, greater<pp>>pq; // min-heap, {wt,node}
    unordered_set<int>visited;
    vector<int>parent(n+1);
    unordered_map<int,int>mp; // {wt,node}
    for(int i=0; i<=n; i++){ // coz of 1 based indexing
        mp[i] = INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
    int edgeCount = 0; // 0 --> n-1
    int cost = 0;

    while(!pq.empty() && edgeCount < n){

        pp curr = pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }

        visited.insert(curr.second);
        edgeCount++;
        cost += curr.first;
        pq.pop();

        for(auto neighbour: graph[curr.second]){ // current me node 2nd hai, graph me node 1st hai

            if(!visited.count(neighbour.first) && mp[neighbour.first] > neighbour.second){

                pq.push({neighbour.second, neighbour.first});
                parent[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }

    return cost;

}

int main(){

    int n,e; // number of vertices and edges
    cin>>n>>e; 

    graph.resize(n+1,list<pair<int,int>>()); // 1 based indexing
    while(e--){

        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt); // bi-directional graph
    }

    int src;
    cin>>src;

    cout<<prims(src,n)<<endl;
    return 0;
}
