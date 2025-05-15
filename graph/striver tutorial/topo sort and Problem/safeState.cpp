#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#include <algorithm>
vector<int> topoSort(int V,vector<int>&indegree,vector<vector<int>>&adj)
    {

       queue<int>q;
       vector<int>ans;
       for(int i=0;i<V;i++)
       {
        if(indegree[i]==0){
            q.push(i);
        }
       }
       while (!q.empty())
       {
          int front=q.front();
          q.pop();
          ans.push_back(front);
          for(auto it:adj[front]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
          }

       }
       return ans;
       
    }
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;  // this is important that we are doing reverse graph but here and 
                // here we are calculating indegree of actual graph not of reversed graph
            }
        }
        vector<int>safe=topoSort(V,indegree,adj);
        sort(safe.begin(),safe.end());
        return safe;
    }
    
};