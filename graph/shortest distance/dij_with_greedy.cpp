#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Function to find the vertex with the minimum distance
int minDistance(const vector<int>& dist, const vector<bool>& visited) {
    int minDist = INF;
    int minIndex = -1;
    int V = dist.size();

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<int>>& graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[source] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited);
        visited[u] = true;
         
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output shortest distances from source
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 4, 1, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 5, 0, 1, 0},
        {0, 0, 0, 0, 3},
        {2, 0, 0, 0, 0}
    };

    // Source node for Dijkstra's algorithm
    int source = 0;

    // Run Dijkstra's algorithm
    dijkstra(graph, source);

    return 0;
}
