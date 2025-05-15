#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordmatching(vector<vector<char>>board,string word,int row,int col,int index,vector<vector<bool>>&visited,int rows,int cols){
        if(index==word.length()){
            return true;
        }
        if(row<0|| row>=rows || col<0 || col>=cols || visited[row][col] || board[row][col]!=word[index]){
            return false;
        }
        visited[row][col]=true;
        vector<vector<int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
        for (const auto& dir : directions) {
            int newR = row + dir[0];
            int newC = col + dir[1];
            if (wordmatching(board, word, newR, newC, index + 1, visited, rows, cols)) {
                return true;
            }
        }
        visited[row][col]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty() || board.empty()){
            return false;
        }
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(wordmatching(board,word,i,j,0,visited,rows,cols)){
                    return true;
                }
            }
        }
        return false;
    }
};


