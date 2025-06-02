#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int MOD = 1000000007;

int numPaths(int curr, int dest, vector<vector<int>>& graph, unordered_set<int>& visited) {
    if (curr == dest) return 1;

    visited.insert(curr); // Mark the current node as visited
    int ways = 0;

    for (auto neighbour : graph[curr]) {
        if (visited.count(neighbour) == 0) { // Only visit unvisited nodes
            ways = (ways + numPaths(neighbour, dest, graph, visited)) % MOD;
        }
    }

    visited.erase(curr); // Unmark the current node
    return ways;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}, {1, 4}, {3, 4}};
    vector<vector<int>> graph(n + 1);

    // Build adjacency list
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    unordered_set<int> visited;
    cout << numPaths(1, n, graph, visited);
    return 0;
}
