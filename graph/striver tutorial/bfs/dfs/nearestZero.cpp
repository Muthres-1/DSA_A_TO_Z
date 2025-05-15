#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,-1));
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        int delR[4]={0,0,-1,1};
        int delC[4]={1,-1,0,0};
        while (!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            if(dist[row][col]==-1){
                dist[row][col]=steps;
            }            
            for(int i=0;i<4;i++){
                int newR=row+delR[i];
                int newC=col+delC[i];
                if(newR<0 || newC<0 || newR>=n || newC>=m || dist[newR][newC]!=-1){
                    continue;
                }
                q.push({{newR,newC},steps+1});
            }
            
        }
        return dist;
        
    }
};

int main()
{

return 0;
}