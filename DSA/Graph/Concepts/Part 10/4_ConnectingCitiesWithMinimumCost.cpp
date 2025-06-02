// LEETCODE 1135

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int find(vector<int>&parent, int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent, parent[a]);
}

void Union(vector<int>&parent, vector<int>&rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }

    else{
        rank[b]++;
        parent[a] = b;
    }
}

bool compare(vector<int>e1, vector<int>e2){
    return e1[2] < e2[2];
}

int krushkals(vector<vector<int>>&EdgeList, int n, int e){

    sort(EdgeList.begin(), EdgeList.end(), compare);
    vector<int>parent(n);
    vector<int>rank(n,0);

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    int edgeCount = 0;
    int i = 0;
    int cost = 0;

    while(edgeCount<n-1 && i<EdgeList.size()){

        int sourceNode = EdgeList[i][0];
        int destNode = EdgeList[i][1];
        int weight = EdgeList[i][2];

        int srcParent = find(parent, sourceNode);
        int destParent = find(parent, destNode);

        if(srcParent != destParent){

            Union(parent, rank, sourceNode, destNode);
            edgeCount++;
            cost+=weight;
        }

        i++;
    }

    return cost;
}

int main(){

    int n = 3; // number of vertices
    vector<vector<int>>EdgeList = {{1,2,5}, {1,3,6}, {2,3,1}};
    int e = EdgeList.size();

    if(e<n){ // or we can use DSU to find number of connected components, if the number of connected components is more than 1, return -1, this implementaion can fail in case of self loop, but not the DSU one
    
        cout<<"Not possible to connect all cities"<<endl;
        return -1;
    }
    cout<<"Minimum cost is: "<<krushkals(EdgeList, n,e)<<endl;
    
    return 0;
}