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

// Brute force way
// the time complexity is O(n*m*(n+m) + (n*m))
void setRow(vector<vector<int>> &mat, int row, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (mat[row][i] == 1)
        {
            mat[row][i] = -1;
        }
    }
}
void setCol(vector<vector<int>> &mat, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] == 1)
        {
            mat[i][col] = -1;
        }
    }
}
void setMatrixZeros(vector<vector<int>> &mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                setRow(mat, i, m);
                setCol(mat, j, n);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = 0;
            }
        }
    }
}

// Better solution 
// The time complexity is O(2*m*n) and the space complexity O(m + n) 
void setMatrixZerosBetter(vector<vector<int>>&mat,int m,int n){
    vector<int>row(n,0);
    vector<int>col(m,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                col[j] = 1;
                row[i] = 1;
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (col[j] == 1 || row[i] == 1)
            {
                mat[i][j] = 0;
            }
            
        }
        
    }
    
    
}

// Optimal solution 
// The time complexity is O(2*M*N)  And the space complexity is O(1)
void setMatrixZerosOptimal(vector<vector<int>>&mat,int m,int n){
    // vector<int>row(n,0); --> mat[.][0]
    // vector<int>col(m,0); --> mat[0][.] // this is from j = 1 to j<m
    // for j ==0th coloum we use cols0 
    int cols0 =1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 0)
            {
                mat[i][0]=0;
                if(j == 0){
                    cols0=0;
                }
                else{
                    mat[0][j]=0;
                }

            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != 0)
            {
                if(j!=0 && (mat[0][j] ==0 || mat[i][0] ==0)){
                    mat[i][j] = 0;
                }
                else if (j == 0 && (cols0 == 0 || mat[i][0] == 0))
                {
                    mat[i][j] = 0;
                }
                
            }
            
        }
        
    }
    
    
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl<<"After setting Zeros"<<endl;
    // setMatrixZeros(mat, n, m);
    // setMatrixZerosBetter(mat,m,n);
    setMatrixZerosOptimal(mat,m,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}