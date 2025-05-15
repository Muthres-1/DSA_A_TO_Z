#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
// this algorithm is used for topological sorting order 
// the topological order is if there is an edge between u and v such that u->v
// then the order will be like - u,v  and u and v can not repetead again 
void make_graph_list(unordered_map<int,list<int>>& adj,vector<pair<int,int>>&edge,int E,int V)
{
    // u->v 1st is u and 2nd is v 
    // here we will store in adj[u]=v; not like---> adj[v]=u;
    // its meaning is that we are storing in adj[i] its outdegree
    for(int i=0;i<E;i++)
    {
        int a=edge[i].first;// u
        int b=edge[i].second;// v
        adj[a].push_back(b);
    }

}

void indeg(vector<int>&indegree,vector<pair<int,int>>&edge,int E)
{
    for(int i=0;i<E;i++)
    {
        int b=edge[i].second;
        indegree[b]++;
    }
}
void kahn_s_algo(vector<pair<int,int>>&edge,vector<int>&ans,int E,int V)
{
    unordered_map<int,list<int>> adj;
    make_graph_list(adj,edge,E,V);
    vector<int>indegree(V);
    indeg(indegree,edge,E);
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        ans.push_back(a);
        for(auto i:adj[a])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

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
    kahn_s_algo(edge,ans,E,V);
    cout<<"the topological order of graph is- ";
    for(int i=1;i<=V;i++)
    {
        cout<<i<<" ";
    }
    return 0;
}
