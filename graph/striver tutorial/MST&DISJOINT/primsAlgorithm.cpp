#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>vis(V,0);
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while (!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum+=wt;          
            for(auto member:adj[node]){
                int adjWt=member[1];
                int adjNode=member[0];
                if(vis[adjNode]==0){
                    pq.push({adjWt,adjNode});
                }            
            }
        }
        return sum;
    }
};