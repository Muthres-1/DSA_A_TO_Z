#include<iostream>
#include<vector>

using namespace std;

class graph {
public:
    vector<vector<int>> adj;
    graph(int n) {
        adj.resize(n);
    }
    
    void addedge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }
    
    int countneighbour(int a) {
        return adj[a].size();
    }
    
    void printadjlist(void) {
        for (int i = 0; i < adj.size(); i++) {
            cout << i << "->";
            for (auto j : adj[i]) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    graph g(n);
    
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    
    cout << "Adjacency List:" << endl;
    g.printadjlist();
    
    cout << "Number of neighbors of vertex 0: " << g.countneighbour(0) << endl;
    
    return 0;
}
