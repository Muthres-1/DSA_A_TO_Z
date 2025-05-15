#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
#include <queue>
#include <limits> // For numeric_limits
#include<algorithm>
using namespace std;
// for non negative weighted and undirected graph
// this algorithm doesn't work for a graph which having negative weighted edge
// the time complexity for dijkstra algorithm is - O(E*log(V))
void shortestDistanceDAG(unordered_map<int, list<pair<int, int>>>& adj, int V, int src, vector<int>& dist) 
{
    dist.assign(V, numeric_limits<int>::max());    
    priority_queue<pair<int,int>> pq; //min heap for pair of node and distance 
    dist[src]=0;
    pq.push(make_pair(src,0));
    while(!pq.empty())
    {
        int node=(pq.top()).first;
        int distance=(pq.top()).second;
        pq.pop();
        for(auto neighbour: adj[node])
        {
            int a=neighbour.first; // neighbour node
            int b=neighbour.second; // neighbour node's weight
            if(dist[a]>b+dist[node])
            {
                dist[a]=b+dist[node];
                pq.push(make_pair(a,dist[a]));
            }

        }
    }

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
        adj[v].push_back({u,w});
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
