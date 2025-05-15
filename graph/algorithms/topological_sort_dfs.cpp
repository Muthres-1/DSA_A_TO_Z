#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<queue>
#include<list>
#include<stack>
using namespace std;

void make_graph_list(unordered_map<int,list<int>>& adj,vector<pair<int,int>>&edge,int E,int V)
{
    for(int i=0;i<E;i++)
    {
        int a=edge[i].first;// u
        int b=edge[i].second;// v
        adj[a].push_back(b);
    }
 
}
void dfs(unordered_map<int,list<int>>&adj,vector<bool>&visited,int i,stack<int>&s)
{
    visited[i]=true;
    for (auto j: adj[i])
    {
       if(!visited[j])
       {
        dfs(adj,visited,j,s);
       }
    }
    s.push(i);
}

void topological_dfs(vector<pair<int,int>>&edge,vector<int>&ans,int E,int V)
{
    unordered_map<int,list<int>> adj;
    make_graph_list(adj,edge,E,V);
    vector<bool>visited(V,false);
    stack<int>s;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(adj,visited,i,s);
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }    
    
}
int main() {
    vector<pair<int,int>> edge;
    int E,V;
    cout<<"enter the number of edges and vertices-";
    cin>>E>>V;
    for(int i=0;i<E;i++)
    {
        int v;
        int u;
        cin>>u>>v; // u->v 1st is u and 2nd is v
       edge.push_back(make_pair(u,v));
    }
    vector<int> ans;
    topological_dfs(edge,ans,E,V);
    cout<<"the topological order of graph is- ";
    for(int i=0;i<=V;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}
