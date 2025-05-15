#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

// for this only one solution so implemention way is very Important
// The time complexity is O(m*n) and the space complexity is also O(m*n)
vector<int> spiralOrderOfMatrix(vector<vector<int>> matrix, int rows, int cols)
{
    vector<int> ans;
    int left = 0, right = cols - 1;
    int top = 0, bottom = rows - 1;
    while (top <= bottom && left <= right)
    {
        // left to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        // top to bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        // right to left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        // bottom to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5, 6}, {20, 21, 22, 23, 24, 7}, {19, 32, 33, 34, 25, 8}, {18, 31, 36, 35, 26, 9}, {17, 30, 29, 28, 27, 10}, {16, 15, 14, 13, 12, 11}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> ans = spiralOrderOfMatrix(matrix, rows, cols);
    cout << "Spiral Traversal of Matrix" << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}