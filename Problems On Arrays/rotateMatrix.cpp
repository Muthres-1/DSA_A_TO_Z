#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

// Brute force way
// The time complexity is O(m*n) and the space complexity is O(m*n) 
vector<vector<int>> rotateMatrix(vector<vector<int>>&mat,int rows,int cols){
    vector<vector<int>>ans=mat; // for defining size two d matrix I forget,how to set size 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ans[j][cols-1-i] = mat[i][j];
            
        }
        
    }
    return ans;
}

// Optimal answer 
// Time complexity is O(m*n/2  + m)  and the space complexity is O(1)
void rotateMatrixOptimal(vector<vector<int>>&mat,int rows,int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = i+1; j < cols; j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
        
    }
    // now here rows are become cols and cols are become rows
    for (int i = 0; i < cols; i++)
    {
        reverse(mat[i].begin(),mat[i].end());
    }   
}
int main()
{
vector<vector<int>>mat={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int rows=mat.size();
int cols=mat[0].size();
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols; j++)
    {
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
}
vector<vector<int>>ans=mat;
// ans=rotateMatrix(mat,rows,cols);
rotateMatrixOptimal(mat,rows,cols);
cout<<endl<<"Matrix After rotation 90 degree"<<endl;
for (int i = 0; i < cols; i++)
{
    for (int j = 0; j < rows; j++)
    {
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}