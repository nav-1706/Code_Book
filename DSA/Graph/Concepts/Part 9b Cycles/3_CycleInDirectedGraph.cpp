/*
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
https://youtu.be/K_LamGUvwUc?si=C_dzVeVh_PtUU7eU
*/

#include<vector>
#include<iostream>
using namespace std;

// https://youtu.be/m6cp4eHWLak?si=l0Yjsu7ktOuFVE8z

class Solution {
public:
    
    vector<bool>visited;
    vector<int>inRec;
    vector<int>count;
    int result = -1;

    bool dfs(int node, vector<int>&edges){ 

        if(node == -1) return;

        visited[node] = true;
        inRec[node] = true;

        int neighbour = edges[node];
        if(neighbour != -1 && visited[neighbour] == false){ // visited nahi hai to inRec bhi nahi hoga

            count[neighbour] = count[node] + 1;
            dfs(neighbour, edges);
        }

        else{
            if(neighbour != -1 && inRec[neighbour] == true){ // Cycle mil gaya
                return true;
            }
        }

        inRec[node] = false;
        return false;
    }

    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        visited.resize(n, false);
        inRec.resize(n, 1);
        count.resize(n, 0);

        for(int i = 0; i<n; i++){
            if(visited[i] == false){

                if(dfs(i, edges)) return true;
            }
        }

        return false;
    }
};