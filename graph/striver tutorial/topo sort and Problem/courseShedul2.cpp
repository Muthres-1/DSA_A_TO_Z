#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


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
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
       int m=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<m;i++){
          adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
          indegree[prerequisites[i][0]]++;
        }
        vector<int>ans=topoSort(numCourses,indegree,adj);

        if(ans.size()==numCourses){
            ans=ans;
        }
        else{
               ans.clear();
        }
        return ans;
    }
};
