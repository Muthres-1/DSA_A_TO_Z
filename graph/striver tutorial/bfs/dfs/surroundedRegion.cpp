#include<iostream>
#include<vector>
using namespace std;

void dfs(int currR,int currC,vector<vector<int>>&vis,int rows,int cols,vector<vector<char>>board,int delR[],int delC[]){
        vis[currR][currC]=1;
        for(int i=0;i<4;i++){
            int newR=currR+delR[i];
            int newC=currC+delC[i];
            if(newR>=0 && newR<rows && newC>=0 && newC<cols && vis[newR][newC]==0 && board[newR][newC]=='O'){
                dfs(newR,newC,vis,rows,cols,board,delR,delC);
            }
        }

}
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        int delR[4]={-1,1,0,0};
        int delC[4]={0,0,-1,1};
        vector<vector<int>>vis(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            // for col=0
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,rows,cols,board,delR,delC);
            }
            // for col=cols-1
            if(!vis[i][cols-1] && board[i][cols-1]=='O'){
                dfs(i,cols-1,vis,rows,cols,board,delR,delC);
            }
        }
        for(int j=0;j<cols;j++){
            // for row=0
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,rows,cols,board,delR,delC);
            }
            // for row=rows-1
            if(!vis[rows-1][j] && board[rows-1][j]=='O'){
                dfs(rows-1,j,vis,rows,cols,board,delR,delC);
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }        
    }
};
int main()
{
 
return 0;
}