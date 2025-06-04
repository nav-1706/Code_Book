/*
2 Operations:
    1. Combine two given sets (union)
    2. Tell if two members belog to same set or not (find) --> leader of set
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int>parent;
vector<int>Rank;

int find(int x){

    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y){

    int x_parent = find(x);
    int y_parent = find(y);

    if(Rank[x_parent] > Rank[y_parent]){

        parent[y_parent] = x_parent;
    }

    else if(Rank[x_parent] < Rank[y_parent]){

        parent[x_parent] = y_parent;
    }

    else{

        parent[y_parent] = x_parent;
        Rank[x_parent]++;
    }
}

int main(){

    int V;
    cin>>V;

    parent.resize(V);
	Rank.resize(V, 0);
    for(int i=0; i<V; i++) parent[i] = i;
}