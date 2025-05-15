#include<iostream>
#include<queue>
#include<vector>
#include <limits.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end)return 0;
        vector<int>dist(100000,INT_MAX);
        dist[start]=0;
        queue<pair<int,int>>q;
        q.push({start,0});// {current,steps}
        while (!q.empty())
        {
            auto it=q.front();
            q.pop();
            int node=it.first;
            int steps=it.second;
            for(auto mem:arr){
                int num=(node*mem)%100000;
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    if(num==end){
                        return steps+1;
                    }
                    q.push({num,steps+1});
                }
            }
        }
        return -1;        
    }
};