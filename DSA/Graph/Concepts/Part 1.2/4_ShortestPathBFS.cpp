/*
In BFS, we traverse the immediate neighbour first together, for this we use queue.

Steps: 
i. Push 0 in queue, pop, then push neighbours of 0, i.e. 1, 4 and mark 1,4 visited

ii. Push neighbours of 1 in queu(3,5) and mark them visited, pop 1

iii. Push neighbour of 4 in queue() (as 0 and 3 both are visited, we will not push them in queue again), pop 4

and on on................

Order: 0, 1, 4, 3, 5, 6, 2
*/

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
#include<climits>
using namespace std;

vector<list<int>>graph; // Graph representation
unordered_set<int>visited; // Set to track visited nodes

int v; // number of vertices

// add edge function
void addEdge(int src, int dest, bool biDir=true){

    graph[src].push_back(dest); // list me push_back kiya hai
    if(biDir){
        graph[dest].push_back(src); // agar bi directional hai to dest me bhi push
    }
}

void bfs(int src, vector<int>&dist){ // no need of destination now

    queue<int>qu;
    visited.clear();

    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);

    while(!qu.empty()){

        int curr = qu.front();
        qu.pop();

        for(auto neighbour: graph[curr]){

            if(!visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour); // yahi par visisted mark kar diya taaki baar baa queue me push na ho 
                dist[neighbour] = dist[curr]+1; // unweighted or works well when all edges have same weight
            }
        }
    }
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

   int x;
   cin>>x;

   vector<int>dist;

   bfs(x,dist);

   for(int i=0; i<dist.size(); i++){

    cout<<dist[i]<<" ";
   }
    return 0;
}