#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minDistFromSourceToDestination(vector<vector<int>>grid,pair<int,int>src,pair<int,int>dest,int rows,int cols){
    if (grid[src.first][src.second] == 1 || grid[dest.first][dest.second] == 1) return -1;
    if (src == dest) return 1;
    queue<pair<int,pair<int,int>>>q;
    vector<vector<int>>dist(rows,vector<int>(cols,1e9));
    q.push({1,src});
    dist[src.first][src.second]=1;
    int delR[8]={-1,0,1,-1,1,0,-1,1};
    int delC[8]={1,1,1,-1,-1,-1,0,0};
    while (!q.empty())
    {
        int distance=q.front().first;
        int r=q.front().second.first;
        int c=q.front().second.second;
        q.pop();
        for(int i=0;i<8;i++){
            int newR=r+delR[i];
            int newC=c+delC[i];
            if(newR>=0 && newR<rows && newC>=0 && newC<cols && grid[newR][newC]==0 && dist[newR][newC]>distance+1){
                dist[newR][newC]=1+distance;
                q.push({dist[newR][newC],{newR,newC}});
            }
        }
    }
    if(dist[dest.first][dest.second]==1e9)return -1;
    return dist[dest.first][dest.second];   

}
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();        
        pair<int,int>src={0,0};
        pair<int,int>dest={rows-1,cols-1};
        return minDistFromSourceToDestination(grid,src,dest,rows,cols);

    }
};

// Something can Optimize
int minDistFromSourceToDestination(vector<vector<int>>grid,pair<int,int>src,pair<int,int>dest,int rows,int cols){
    if (grid[src.first][src.second] == 1 || grid[dest.first][dest.second] == 1) return -1;
    if (src == dest) return 1;
    queue<pair<int,pair<int,int>>>q;
    vector<vector<int>>dist(rows,vector<int>(cols,1e9));
    q.push({1,src});
    dist[src.first][src.second]=1;
    int delR[8]={-1,0,1,-1,1,0,-1,1};
    int delC[8]={1,1,1,-1,-1,-1,0,0};
    while (!q.empty())
    {
        int distance=q.front().first;
        int r=q.front().second.first;
        int c=q.front().second.second;
        q.pop();
        for(int i=0;i<8;i++){
            int newR=r+delR[i];
            int newC=c+delC[i];
            if(newR>=0 && newR<rows && newC>=0 && newC<cols && grid[newR][newC]==0 && dist[newR][newC]>distance+1){
                dist[newR][newC]=1+distance;
                if (newR == dest.first && newC == dest.second)return distance + 1;
                q.push({dist[newR][newC],{newR,newC}});
            }
        }
    }
    if(dist[dest.first][dest.second]==1e9)return -1;
    return dist[dest.first][dest.second];   

}
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();        
        pair<int,int>src={0,0};
        pair<int,int>dest={rows-1,cols-1};
        return minDistFromSourceToDestination(grid,src,dest,rows,cols);

    }
};