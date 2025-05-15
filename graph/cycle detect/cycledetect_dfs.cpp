#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;


bool cycle_dfs_use(int node,int parent,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj)
{   
    visited[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
          bool a=cycle_dfs_use(i,node,visited,adj);
          if(a)
          {
            return true;
          }
        }
        else if(i!=parent) // I is not the parent of node
        {
            //cycle present
            return true;
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
        bool l=cycle_dfs_use(i,-1,visited,adj);
        if(l)
        {
            cout<<"cycle is present"<<endl;
            return ;
        }
    }
   }
   cout<<"there is no any cycle in this graph"<<endl;    
   
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
 is_cycle_detect(V,E,edge);

return 0;
}