// Cycle detection in undirected graph using DSU, if edge list is given

/*

Algorithm:
    1. First we need graph in edge-list format -> ek ek edge lo aur check karo ki kya vo pahle se hi same group me hai, agar hai to seedha return karo ki cycle exist karti hai

    agar nahi then unka union le lo

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int find(vector<int>&parent, int x){
    // TC = O(l*logn)
    // this method returns which group/cluster x belongs to

    if (parent[x] == x) return x;
    return parent[x] = find(parent,parent[x]);

}

void Union(vector<int>&parent, vector<int>&rank, int a, int b){
    // TC = O(l*logn)
    
    a = find(parent,a);
    b = find(parent,b);

    // if(a==b) return true; // already same group me hai --> cycle exists
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }

    else{
        rank[b]++;
        parent[a] = b;
    }

    // return false; // cycle don't exists
}

int main(){

    int n, m;
    cin>>n>>m;
    bool isCycle = false;
    // n --> elements, m --> number of edges

    vector<int> parent(n+1);
    vector<int> rank(n+1,0); // initailly all 0

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    while(m--){

        int x,y;
        cin>>x>>y;
        if(find(parent,x) == find(parent,y)){
            cout<<"Cycle exists"<<endl;
            isCycle = true;
            break;
        }
        //bool flag = Union(parent,rank,x,y);
        //if(flag) cout<<"Cycle exists"<<endl;
        //break;

        else{
            Union(parent,rank,x,y);
        }
    }

    if(!isCycle) cout<<"Cycle does't exist"<<endl;

    return 0;
}

// TC: O(union TC * number of edges) == O(log*n x E) ~= O(E)