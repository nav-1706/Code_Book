#include<iostream>
#include<vector>
#include<string>
using namespace std;

int find(vector<int>&parent, int x){
    // TC = O(l*logn)
    // this method returns which group/cluster x belongs to

    if (parent[x] == x) return x;
    return parent[x] = find(parent,parent[x]); //path compression

}

void Union(vector<int>&parent, vector<int>&rank, int a, int b){ // union by ranks
    // TC = O(l*logn)
    
    a = find(parent,a);
    b = find(parent,b);

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }

    else{
        rank[b]++;
        parent[a] = b;
    }
}

int main(){

    int n, m;
    cin>>n>>m;
    // n --> elements, m --> number of queries

    vector<int> parent(n+1);
    vector<int> rank(n+1,0); // initailly all 0

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    while(m--){

        string str;
        cin>>str;
        if(str == "union"){

            int x,y;
            cin>>x>>y;
            Union(parent,rank,x,y);
        }

        else{
            int x;
            cin>>x;
            cout<<find(parent,x)<<endl;
        }
    }
}