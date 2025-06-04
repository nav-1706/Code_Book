// Multisource shortest distance algorithm --> Find the shortest distance between  every pair of vertices in a given edge-weight directed graph

// Make Un-Directed graph Directed by making two edges 

// The graph may contain negative edge weights, but it does not contain any negative weight cycles. but can detect the negative cycle --> diagonal elements (dist[i][i]) must be 0

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != 1e9 && dist[via][j] != 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }
};