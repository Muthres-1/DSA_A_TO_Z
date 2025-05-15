#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

bool cycle_bfs_use(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=true;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto neighbour:adj[front])
        {
            if(visited[neighbour]==true&& neighbour!=parent[front]) // neighbour is not the parent of front
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=front; // the parent of neighbour is front
            }
        }
    }
    return false;    
}
void is_cycle_detect(int V,int E,vector<vector<int>>&edge)
{
   unordered_map<int,list<int>> adj;
   for(int i=0;i<edge.size();i++)
   {
    int u=edge[i][0];
    int v=edge[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
   }  
   unordered_map<int,bool> visited;// by default it contain false value
   for(int i=0;i<adj.size();i++)
   {
    if(!visited[i])
    {        
        bool l=cycle_bfs_use(i,visited,adj);
        if(l)
        {
            cout<<"cycle is present in this component"<<endl;
            if(i==adj.size()-1)
            return ;            
        }
    }
   }
   cout<<"there is no any cycle in this graph"<<endl;    
   
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
    is_cycle_detect(V,E,edge);
   
    return 0;
}
