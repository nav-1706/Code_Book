// weighted graph

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector< unordered_map<int,int> >graph;
int v; // number of vertices

void addEdge(int src, int dest, int wt, bool biDir=true){ // src == i

    graph[src][dest] = wt; // graph(vector) ke src index me ek 'dest' kaam ki key hai jiski value 'wt' hai

    /*
    graph[src] --> ye karne par ham vector ke 'src'(i) index par aa gaye
    graph[src][dest] --> ye karne par ham vector ke 'src'(i) index par rakhe map ki 'key' par aa gaye
    graph[src][dest] --> ye karne par ham vector ke 'src'(i) index par rakhe map ki 'key' par 'wt' (value) ko store kar diya
    */
    if(biDir){
        graph[dest][src] = wt;
    }
}

void display(){

    for(int i=0; i<graph.size(); i++){ // i == src
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
    graph.resize(v, unordered_map<int,int>());

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