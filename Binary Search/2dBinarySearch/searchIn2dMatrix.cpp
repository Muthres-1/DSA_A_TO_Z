#include<iostream>
#include<vector>
using namespace std;

// Here entire matrix is sorted in the manner of like if we do flat whole matrix then also it will generate the 
// sorted matrix 
// Brute force Approach
pair<int,int> searchIn2dMatrix(vector<vector<int>>matrix,int target){
int rows=matrix.size(),cols=matrix[0].size();
for (int i = 0; i < rows; i++)
{
    for(int j=0;j<cols;j++){
        if(matrix[i][j]==target){
            return {i,j};
        }
    }
    
}
return {-1,-1};
}
// Optimized solution 

int findInd(int target,vector<int>arr,int length){
    int left=0;
    int right=length-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;// to resolve overflow problem
        if(arr[mid]==target){
            return mid;
        }
        else if (arr[mid]>target)
        {
            right=mid-1;
        }
        else{
            left=mid+1;// Here if we do just left=mid then it stuck into infinite loop when we check target = arr[length-1]
        }
        
    }
    
    return -1;
}

pair<int,int> searchIn2dMatrixOptimized(vector<vector<int>>matrix,int target){
int rows=matrix.size(),cols=matrix[0].size();
for (int i = 0; i < rows; i++)
{
    if(target>=matrix[i][0] && target<=matrix[i][cols-1]){
    int index=findInd(target,matrix[i],cols);
    if(index!=-1)return {i,index};    
    }    
}
return {-1,-1};
}

// More Optimized  using flattening 
pair<int,int> searchUsingFlattening(vector<vector<int>>mat,int target){
    int rows=mat.size();
    int cols=mat[0].size();
    int low=0,high=rows*cols-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        int r=mid/cols,c=mid%cols;
        if(mat[r][c]==target){
            return {r,c};
        }
        else if(target>mat[r][c]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return {-1,-1};
}


int main()
{
vector<vector<int>>matrix={{2,4,7,9},{12,13,16,18},{20,21,23,27}};
int target;
cin>>target;
pair<int,int>ans=searchIn2dMatrix(matrix,target);
cout<<ans.first<<","<<ans.second<<endl;
// ans=searchIn2dMatrixOptimized(matrix,target);
// cout<<ans.first<<","<<ans.second<<endl;
ans=searchUsingFlattening(matrix,target);
cout<<ans.first<<","<<ans.second<<endl;
return 0;
}