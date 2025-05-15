#include<iostream>
#include<vector>            
#include<unordered_map>
#include<list>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

void bfs_for_parent(unordered_map<int,list<int>>adj,unordered_map<int,int>&parent,unordered_map<int,bool>&visited,int V,int node)
{
  queue<int> q;
  q.push(node);
  visited[node]=true; 
  parent[node]=-1; // the parent of node is -1
  // set the parent for every node
  while(!q.empty())
  {
    int front=q.front();
    q.pop();
    for(auto i:adj[front])
    {
        if(!visited[i])
        {
          visited[i]=true;             
          parent[i]=front; // the parent of neighbour is front;
          q.push(i);
        }
    }
  }
  // in general there may also possible more than one parent of any node but here we used bfs for parent and by this
  // we are defining only a single parent of any node here can not possible more than one parent of any node 
  // 

}
void shortest_path(vector<vector<int>>&edge,vector<int>&ans,int E,int V,int src,int des)
{
  unordered_map<int,list<int>> adj;
  for(int i=0;i<E;i++)
  {
    int a=edge[i][0];
    int b=edge[i][1];    
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  unordered_map<int,int> parent;  // parent of a node may also more than one but in this case there will not be more than one
  unordered_map<int,bool> visited;    
  for(int i=0;i<V;i++)
  {
    if(!visited[i])
    {
      bfs_for_parent(adj,parent,visited,V,i);
    }
  }
int currnod=des;
ans.push_back(des);
while(currnod!=src)
{
   currnod=parent[currnod];
   ans.push_back(currnod);
}
  reverse(ans.begin(),ans.end());

}

int main()
{
  int V,E;
  cout<<"give input the number of edges and number of vertices -";
  cin>>E>>V;
  vector<vector<int>> edge;
  for(int i=0;i<E;i++)
  {
    int u,v;
    cin>>u>>v;
    edge.push_back({u, v});
  }
 vector<int>ans;
 int s,d;
 cout<<endl<<"give input the source node and destination node-";
 cin>>s>>d;
 shortest_path(edge,ans,E,V,s,d);
for(int i=0;i<ans.size();i++)
{
  cout<<ans[i]<<" ";
}
return 0;
}