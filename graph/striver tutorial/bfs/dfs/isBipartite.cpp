#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dfs(int node,int c,vector<int>&color,vector<vector<int>>graph){
    color[node]=c;
    for(auto ng:graph[node]){
      if(color[ng]==-1){
        if(dfs(ng,!c,color,graph)==false)return false;
      }
      else if(color[ng]==c){
        return false;
      }
    }
    return true;
}
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false)return false;
            }
        }
        return true;
    }
};
