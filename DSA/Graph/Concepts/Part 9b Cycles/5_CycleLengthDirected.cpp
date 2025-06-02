// https://youtu.be/m6cp4eHWLak?si=l0Yjsu7ktOuFVE8z
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    vector<bool>visited;
    vector<int>inRec;
    vector<int>count;
    int result = -1;

    void dfs(int node, vector<int>&edges){ 

        if(node == -1) return;

        visited[node] = true;
        inRec[node] = true;

        int neighbour = edges[node];
        if(neighbour != -1 && visited[neighbour] == false){
            count[neighbour] = count[node] + 1;
            dfs(neighbour, edges);
        }

        else{
            if(neighbour != -1 && inRec[neighbour] == true){ // Cycle mil gaya
                result = max(result, count[node]-count[neighbour]+1);
            }
        }

        inRec[node] = false;
    }

    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        visited.resize(n, false);
        inRec.resize(n, 1);
        count.resize(n, 0);

        for(int i = 0; i<n; i++){
            if(visited[i] == false){

                dfs(i, edges);
            }
        }

        return result;;
    }
};