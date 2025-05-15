#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
#include <queue>
#include <limits> // For numeric_limits
#include<algorithm>
using namespace std;

void topologicalSortUtil(int v, vector<bool>& visited, vector<int>& stack, unordered_map<int, list<pair<int, int>>>& adj) {
    visited[v] = true;

    for (auto& neighbor : adj[v]) {
        if (!visited[neighbor.first]) {
            topologicalSortUtil(neighbor.first, visited, stack, adj);
        }
    }

    stack.push_back(v);
}

vector<int> topologicalSort(unordered_map<int, list<pair<int, int>>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<int> stack;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack, adj);
        }
    }

    reverse(stack.begin(), stack.end());
    return stack;
} 

void shortestPath(unordered_map<int, list<pair<int, int>>>& adj, int src, vector<int>& dist, vector<int>& topologicalOrder)
{
    dist[src] = 0;

    for (int u : topologicalOrder) 
    {      
            for (auto neighbor : adj[u]) 
            {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[v] > dist[u] + weight) 
                {
                    dist[v] = dist[u] + weight;
                }
            }    
    }
}

void shortestDistanceDAG(unordered_map<int, list<pair<int, int>>>& adj, int V, int src, vector<int>& dist) {
    vector<int> topologicalOrder = topologicalSort(adj, V);
    dist.assign(V, numeric_limits<int>::max());

    shortestPath(adj, src, dist, topologicalOrder);
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    unordered_map<int, list<pair<int, int>>> adj;
    cout << "Enter the edges and weights (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
 
    int src;
    cout << "Enter the source node: ";
    cin >> src;

    vector<int> dist;
    shortestDistanceDAG(adj, V, src, dist);

    cout << "Shortest distances from node " << src << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}
