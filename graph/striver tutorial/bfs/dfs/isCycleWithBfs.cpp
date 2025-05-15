#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool bfs(int node,int V,vector<int>adj[],int visited[]){
    queue<pair<int,int>>q;
    visited[node]=1;
    q.push({node,-1});
    while (!q.empty())
    {
        int currNode=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto member:adj[currNode]){
            if(visited[member]==0){
                visited[member]=1;
                q.push({member,currNode});
            }
            else if (member!=parent)
            {
                return true;
            }            
        }        
    }
    return false;    
}
class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
       int visited[V]={0};
       for(int i=0;i<V;i++){
           if(!visited[i]){
               if(bfs(i,V,adj,visited)){
                   return true;
               }
               
           }
       }
       return false;
    }
};