#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> shortestDist(vector<vector<int>>&adj,int N,int src){
    vector<int>ans(N,1e9);
    queue<int>q;
    q.push(src);
    ans[src]=0;
    while (!q.empty())
    {
        int front =q.front();
        q.pop();
        for(auto it:adj[front]){
            if(ans[front]+1<ans[it]){
                ans[it]=ans[front]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(ans[i]==1e9){
            ans[i]=-1;
        }
    }    
    return ans;
}
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>>adj(N);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return shortestDist(adj,N,src);
    }
};


// for undirected weighted graph use this function instead of shortestPath 
vector<int> shortestDist2(vector<vector<pair<int,int>>>adj,int N,int src){
    vector<int>ans(N,1e9);
    ans[src]=0;
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto it:adj[a]){
            if(ans[a]+it.second<ans[it.first]){
                ans[it.first]=ans[a]+it.second;
                q.push(it.first);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(ans[i]==1e9){
            ans[i]=-1;
        }
    }
    return ans;    
}