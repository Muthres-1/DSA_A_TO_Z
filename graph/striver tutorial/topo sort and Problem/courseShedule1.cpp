#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
bool isCyclic(int V, vector<vector<int>>adj,vector<int>indegree)
    {       
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

class Solution
{

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int m=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<m;i++){
          adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
          indegree[prerequisites[i][0]]++;
        }
        return !isCyclic(numCourses,adj,indegree);
    }
};

int main()
{

    return 0;
}