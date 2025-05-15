#include<iostream>
#include<vector>
using namespace std;


bool dfs(int currNode,int parent,int V,vector<int>adj[],int vis[]){
    vis[currNode]=1;
    for(auto member:adj[currNode]){
        if(vis[member]==0){
            if(dfs(member,currNode,V,adj,vis)==true){
                return true;
            }
        }
        else if(member!=parent)return true;
    }
    return false;
}
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V]={0};
       for(int i =0;i<V;i++){
           if(vis[i]==0){
               if(dfs(i,-1,V,adj,vis))return true;
           }
       }
       return false;
    }
};
int main()
{

return 0;
}