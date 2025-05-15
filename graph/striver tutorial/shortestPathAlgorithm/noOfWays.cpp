#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int mode=int(1e9 + 7);
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            int wt=it[2];
            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long> dist(n, LLONG_MAX);
        vector<int>ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        while (!pq.empty())
        {
            long long distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjWt=it.second;
                if(distance+adjWt<dist[adjNode]){
                    dist[adjNode]=distance+adjWt;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(distance+adjWt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mode;
                }
            }
        }
        return ways[n-1]%mode;
        
    }
};