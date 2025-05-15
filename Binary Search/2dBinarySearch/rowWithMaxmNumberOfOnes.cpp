#include<iostream>
#include<vector>
using namespace std;

// Brute force Approach
int findRowWithMaxOnes(vector<vector<int>>matrix){
int index=-1,maxCount=-1;
int rows=matrix.size(),cols=matrix[0].size();
for (int i = 0; i < rows; i++)
{
    int countOneInARow=0;
    for(int j=0;j<cols;j++){
        if(matrix[i][j]==1){
            countOneInARow++;
        }
    }
    if(countOneInARow>maxCount){
        maxCount=countOneInARow;
        index=i;
    }
}
return index;
}
// Optimized answer
int findLowerBound(int target,vector<int>arr,int length){
    int left=0;
    int right=length-1;
    int ans=length;
    while (left<=right)
    {
        int mid=left+(right-left)/2;// to resolve overflow problem
        if(arr[mid]>=target){
            ans=mid;
            right=mid-1;
        }
        else// because the mid is not possible as answer 
        {
            left=mid+1;
        }                
    }    
    return ans;
}

int findRowWithMaxOnesOptimized(vector<vector<int>>matrix){
    int index=-1,maxCount=-1;
    int rows=matrix.size();
    int cols=matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        int countOneInRow=cols-findLowerBound(1,matrix[i],cols);
        if(countOneInRow>maxCount){
            maxCount=countOneInRow;
            index=i;
        }
    }
    return index;
}
int main()
{
vector<vector<int>>matrix={{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
cout<<findRowWithMaxOnes(matrix)<<endl;
cout<<findRowWithMaxOnesOptimized(matrix)<<endl;
return 0;
}