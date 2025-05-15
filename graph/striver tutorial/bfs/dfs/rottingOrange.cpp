#include <vector>
#include <queue>
#include <utility>

using namespace std;

int Rotting(vector<vector<int>>& grid, vector<vector<int>>& othGrid, int rows, int cols, queue<pair<int, int>>& q) {
    int delRows[4] = {-1, 1, 0, 0};
    int delCols[4] = {0, 0, -1, 1};
    int count = 0;
    
    while (!q.empty()) {
        int size = q.size();
        bool progress = false; 

        for (int i = 0; i < size; ++i) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            
            for (int j = 0; j < 4; ++j) {
                int nextRow = currRow + delRows[j];
                int nextCol = currCol + delCols[j];
                
                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || grid[nextRow][nextCol] != 1) {
                    continue;
                }
                
                q.push({nextRow, nextCol});
                grid[nextRow][nextCol] = 2;
                progress = true;
            }
        }
        
        if (progress) {
            ++count;
        }
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    
    return count;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        return Rotting(grid, grid, rows, cols, q);
    }
};
