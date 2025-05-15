#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>res(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if((i==rows-1 || i==0 || j==cols-1 || j==0 )&& (grid[i][j]==1)){
                    q.push({i,j});
                }
            }
        }
        int delR[4]={0,0,-1,1};
        int delC[4]={-1,1,0,0};
        while (!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();        
            res[r][c]=1;            
            for(int i=0;i<4;i++){
                int nR=r+delR[i];
                int nC=c+delC[i];
                if(nR>=rows || nR<0 || nC>=cols || nC<0 || res[nR][nC]==1){
                    continue;
                }
                if(grid[nR][nC]==1){
                  q.push({nR,nC});
                }
            }            

        }
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(res[i][j]==0 && grid[i][j]==1){
                    count+=1;
                }
            }
        }
        return count;
        
    }
};

// 