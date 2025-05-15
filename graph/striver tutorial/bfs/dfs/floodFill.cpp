#include<iostream>
#include<vector>
using namespace std;

void fillGrid(vector<vector<int>>image,vector<vector<int>>&grid,int sr,int sc,int newColor,int color,int delR[],int delC[]){
    grid[sr][sc]=newColor;
    int rows=image.size();
    int cols=image[0].size();
    for(int i=0;i<4;i++){
        int newR=sr+delR[i];
        int newC=sc+delC[i];
        if(newR>=rows || newR<0 || newC<0 || newC>=cols || image[newR][newC]!=color || grid[newR][newC] == newColor){
            continue;
        }
        grid[newR][newC]=newColor;
        fillGrid(image,grid,newR,newC,newColor,color,delR,delC);
    }
}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>grid=image;
        int color=grid[sr][sc];
        int delR[4]={-1,1,0,0};
        int delC[4]={0,0,-1,1};
        fillGrid(image,grid,sr,sc,newColor,color,delR,delC);
        return grid;
    }
};
int main()
{

return 0;
}