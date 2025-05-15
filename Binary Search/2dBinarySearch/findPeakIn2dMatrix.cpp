#include<iostream>
#include<vector>
using namespace std;

// Brute force --> just do check in all four direction for each cell as brute force manner The time 
// Complexity will be for this type of brute force is O(m*n*4) 
// we can optimize it to O(m*n) checking the largest element and return it 
// Now we want to optimized further more which is provided following 

// here  matrix don't need to be sorted ,In 1D also don't need to be sorted 
// Time complexity is O(n*log2(m))
int findMaxIndex(vector<vector<int>>matrix,int rows,int cols,int coloum){
    int index=-1;
    int ans=INT_MIN;
    for(int i=0;i<rows;i++){
        if (ans<matrix[i][coloum])
        {
            ans=matrix[i][coloum];
            index=i;
        }        
    }
    return index;
}
pair<int,int> findPeakIn2dMatrix(vector<vector<int>>matrix){
int rows=matrix.size();
int cols=matrix[0].size();
int low=0,high=cols-1;
while (low<=high)
{
    int mid=low+(high-low)/2;
    int maxRowIndex=findMaxIndex(matrix,rows,cols,mid);
    int left=mid-1>=0?matrix[maxRowIndex][mid-1]:-1;
    int right=mid+1<cols?matrix[maxRowIndex][mid+1]:-1;
    if(matrix[maxRowIndex][mid]>left && matrix[maxRowIndex][mid]>right){
        return {maxRowIndex,mid};
    }else if (matrix[maxRowIndex][mid]< left){
        high=mid-1;
    }else{
        low=mid+1;
    }        
}
return {-1,-1};
}
int main()
{
vector<vector<int>>matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
pair<int,int>ans=findPeakIn2dMatrix(matrix);
cout<<ans.first<<","<<ans.second<<endl;
return 0;
}