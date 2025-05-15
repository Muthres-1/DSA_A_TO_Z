#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

int bfs(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited) {
    queue<int> q;
    visited[node] = true; 
    q.push(node);
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    } 
    return 1;
} 
int breadth_first_search(int V, int E, vector<vector<int>>& edge) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < E; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count=0;
    unordered_map<int, bool> visited; // default is false 
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            count+= bfs(i, adj, visited);
        
        }
    }
    return count;
}
// the output is asked to give no of total component 