#include<iostream>
#include<vector>
#include<queue>
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
    bool isCyclic(int V, vector<int> adj[])
    {
       vector<int>indegree=indegre(adj,V);
       queue<int>q;
       int count=0;
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
          count++;
          for(auto it:adj[front]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
          }
       }
       if(count==V)return false;
       return true;
       
    }
};

int main()
{

return 0;
}