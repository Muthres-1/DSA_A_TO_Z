#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

 
void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,vector<int>&component)
{
    component.push_back(node);
    visited[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
          dfs(i,visited,adj,component);
        } 
    }
}
vector<vector<int>> depth_first_search(int V,int E,vector<vector<int>>&edge)
{
   unordered_map<int,list<int>> adj;
   for(int i=0;i<edge.size();i++)
   {
    int u=edge[i][0];
    int v=edge[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   vector<vector<int>> ans;
   unordered_map<int,bool> visited;// by default it contain false value
   for(int i=0;i<adj.size();i++)
   {
    if(!visited[i])
    {
        vector<int>component;
        dfs(i,visited,adj,component);
        ans.push_back(component);
    }
   }
   return ans;
   
}
void print(vector<vector<int>>ans)
{
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
  int V,E;
  cout<<"give input the number of vertices and number of edges-";
  cin>>V>>E;
  vector<vector<int>> edge(E, vector<int>(2));
  for(int i=0;i<E;i++)
  {
    int u,v;
    cin>>u>>v;
    edge[i][0]=u;
    edge[i][1]=v;
  }
 vector<vector<int>>ans=depth_first_search(V,E,edge);
 print(ans);
return 0;
}