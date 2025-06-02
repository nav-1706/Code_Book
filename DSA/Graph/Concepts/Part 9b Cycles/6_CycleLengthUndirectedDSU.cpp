#include<iostream>
#include<vector>
using namespace std;

int find(int x, vector<int>&parent){

    if(x == parent[x]) return x;

    return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int>&size, vector<int>&parent){

    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if(x_parent == y_parent) return;

    if(size[x_parent] > size[y_parent]){

        parent[y_parent] = x_parent;
        size[x_parent] += size[y_parent];
    }

    else if(size[x_parent] < size[y_parent]){

        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];
    }

    else{
        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];
    }

}

int main(){

    vector<vector<int>>edges = {{0,1},{1,2},{2,3},{3,4},{4,5},{0,7},{0,6},{5,7},{5,6}};
    int n = 8;

    vector<int>parent(n);
    for(int i = 0; i<n; i++) parent[i] = i;
    vector<int>size(n, 1);

    for(auto edge: edges){

        int u = edge[0];
        int v = edge[1];

        if(find(u, parent) == find(v, parent)){
            cout<<size[find(u, parent)]<<" ";
        }

        else{
            Union(u, v, size, parent);
        }
    }
}