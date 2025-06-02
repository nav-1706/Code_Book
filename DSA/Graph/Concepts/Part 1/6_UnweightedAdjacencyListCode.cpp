// unweighted graph

#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>>graph;
int v; // number of vertices

void addEdge(int src, int dest, bool biDir=true){

    graph[src].push_back(dest); // list me push_back kiya hai
    if(biDir){
        graph[dest].push_back(src); // agar bi directional hai to dest me bhi push
    }
}

void display(){

    for(int i=0; i<graph.size(); i++){
        cout << i << "-->";
        for(auto ele: graph[i]){
            cout<<ele<<", ";
        }
        cout<<endl;
    }
}

int main(){

    cout<<"Enter the number of vertices"<<endl;
    cin>>v;
    graph.resize(v, list<int>()); // array ka size number of vertices ke equal kar diya

    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    while(e--){

        int s,d;
        cout<<"Enter source vertex"<<endl;
        cin>>s;

        cout<<"Enter destination vertex"<<endl;
        cin>>d;

        addEdge(s,d); // for directed graph just add false in agrument

    }

    display();

    return 0;
}