// weighted graph

#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector< list< pair< int,int > > >graph;
int v; // number of vertices

void addEdge(int src, int dest, int wt, bool biDir=true){

    graph[src].push_back( {dest,wt} ); // list me push_back kiya hai
    if(biDir){
        graph[dest].push_back( {src,wt} ); // agar bi directional hai to dest me bhi push
    }
}

void display(){

    for(int i=0; i<graph.size(); i++){
        cout << i << "-->";
        for(auto ele: graph[i]){
            cout<<"("<<ele.first<<", "<<ele.second<<")"<<", ";
        }
        cout<<endl;
    }
}

int main(){

    cout<<"Enter the number of vertices: ";
    cin>>v;
    graph.resize(v, list<pair<int,int>>());

    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    while(e--){

        int s,d,w;
        cout<<"Enter source vertex: ";
        cin>>s;

        cout<<"Enter destination vertex: ";
        cin>>d;

        cout<<"Enter the weight between the two vertex: ";
        cin>>w;

        addEdge(s,d,w); // for directed graph just add false in agrument

        cout<<endl;
    }

    display();

    return 0;
}