#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

vector<int> bfs(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited) {
    vector<int> component;
    queue<int> q;
    visited[node] = true; 
    q.push(node);
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        component.push_back(currentNode);
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    } 
    return component;
} 

vector<vector<int>> breadth_first_search(int V, int E, vector<vector<int>>& edge) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < E; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int, bool> visited; // default is false 
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component = bfs(i, adj, visited);
            ans.push_back(component);
        }
    }
    return ans;
}

void print(vector<vector<int>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and number of edges: ";
    cin >> V >> E;
    vector<vector<int>> edge(E, vector<int>(2));
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edge[i][0] = u;
        edge[i][1] = v;
    }
    vector<vector<int>> ans = breadth_first_search(V, E, edge);
    cout << "Connected Components:" << endl;
    print(ans);
    return 0;
}
