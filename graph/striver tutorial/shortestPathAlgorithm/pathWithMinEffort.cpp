#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minDistFromSourceToDestination(vector<vector<int>>heights,pair<int,int>src,pair<int,int>dest,int rows,int cols){
    if (src == dest) return 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
    pq.push({0,{0,0}});
    vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while (!pq.empty())
    {
        int diff=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        pq.pop();
        if (row==rows-1 && col ==cols-1)return diff;
        for(int i=0;i<4;i++){
            int newR=row+dr[i];
            int newC=col+dc[i];
            int newr = row + dr[i];
                int newc = col + dc[i];
                if (newr >= 0 && newc >= 0 && newr < rows && newc < cols)
                {
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }

        }

    }
    return 0;    
}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();        
        pair<int,int>src={0,0};
        pair<int,int>dest={rows-1,cols-1};
        return minDistFromSourceToDestination(heights,src,dest,rows,cols);
    }
};