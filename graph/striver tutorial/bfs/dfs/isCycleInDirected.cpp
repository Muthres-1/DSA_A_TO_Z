#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node,int vis[],int pathVis[],vector<int>adj[]){
    vis[node]=1;
    pathVis[node]=1;
    for(auto member:adj[node]){
        if(!vis[member]){
            if(dfs(member,vis,pathVis,adj)==true)return true;
        }
        else if(pathVis[member]){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true)return true;
            }
        }
        return false;
    }
};

int main()
{

return 0;
}