// topological sorting order using bfs
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    vector<int> indegre(vector<int> adj[], int V)
    {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        return indegree;
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
       vector<int>indegree=indegre(adj,V);
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
};