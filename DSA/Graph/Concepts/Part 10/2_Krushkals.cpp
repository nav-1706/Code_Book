/*

REMEMBER:
When we create a MST, there is only one path from one node to another, and every node is connected to every other node, directlty or indirectly

Time Complexity:

TC of sorting: O(e * loge) 
TC of while loop: O(n * TC(find and union))
TC of find and union: log(*n)  (and log(*n) ~= constant, Hence TC of while loop = O(n))
Overall TC of krushkals algorithm: O(n + e*loge)

n --> number of vertices
e --> number of edges

Helpful when edge-list is given

*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#define ll long long int
using namespace std;

int find(vector<int>&parent, int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent, parent[a]);
}

void Union(vector<int>&parent, vector<int>&rank, int a, int b){

    a = find(parent, a); // parent of a
    b = find(parent, b);

    if(a==b) return;

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }

    else{
        rank[b]++;
        parent[a] = b;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool compare(Edge e1, Edge e2){
    return e1.wt < e2.wt; // increasing order
}

ll krushkals(vector<Edge>&input, int n, int e){ // n --> number of vertecies, e --> number of edges

    sort(input.begin(), input.end(), compare);
    vector<int>parent(n+1); // (n+1) size
    vector<int>rank(n+1, 1); // 1 se initailize

    for(int i=0; i<=n; i++){
        parent[i] = i; // initailly sab apne khud ke parent hai
    }

    int edgeCount = 0;  // we have to select all vertices, and for tree with 'n' vertices, the edgeCount must be equal to 'n-1'

    int i=0;
    ll ans = 0;

    while(edgeCount<n-1 && i<input.size()){ // n-1 se jayda edges hai that 100% mean ki aage loop hai
        Edge curr = input[i]; 
        int sourceNode = curr.src;
        int destNode = curr.dest;
        int weight = curr.wt;

        int sourceParent = find(parent,sourceNode);
        int destParent = find(parent,destNode);

        if(sourceParent != destParent){
            // include this edge, this will not create a cycle
            Union(parent,rank, sourceNode,destNode);
            ans+=weight;
            edgeCount++;
        }

        i++; // doesn't matter if you picked last edge or not, we still need to go to next edge
    }

    return ans;
}   

int main(){

    int n; // number of vertices
    int e; // number of edges

    cin>>n>>e;

    vector<Edge>v(e);
    for(int i=0; i<e; i++){
        
        cin>>v[i].src>>v[i].dest>>v[i].wt; // direct input le liya
    }

    cout<<"Minimum spanning tree weight: "<<krushkals(v,n,e)<<endl;
    return 0;
}