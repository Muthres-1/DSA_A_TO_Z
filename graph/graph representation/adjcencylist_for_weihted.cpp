#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

// weighted graph representation with adjcecncy list 
class graph {
    int V;
    int E;
    unordered_map<int, list<pair<int, int>>> adj;

public:
    graph(int ver,int edge)
    {
        V=ver;
        E=edge;
    }

    void addedge(int u, int v, int wt) {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    void printGraph() {
        int v, w;
        for (int u = 0; u < V; u++) {
            cout << "Node " << u << " makes an edge with \n";
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                v = it->first;
                w = it->second;
                cout << "\tNode " << v << " with edge weight = " << w << "\n";
            }
            cout << "\n";
        }
    }
};

int main() {
    
 int n;
 cout<<"Enter the number of vertices -";
 cin>>n;
 int m;
 cout<<endl<<"Enter the number of edges ";
 cin>>m;
 graph g(n,m);
 for(int i=0;i<m;i++) // because we are passing edge that's why this will go on up to m times
 {
    int u,v,w;
    cin>>u>>v>>w;
    g.addedge(u,v,w);
 }
    g.printGraph();
    return 0;
}
