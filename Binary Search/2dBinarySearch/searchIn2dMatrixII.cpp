#include<iostream>
#include<vector>
using namespace std;


// here matrix is just sorted in indivisual row and coloum but when we flat the whole matrix then it doesn't 
// appear sorted manner 
// first brute force 
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

// This is the Important for this perticular kind of matrix having such property in that indivisual row and coloums are sorted 
pair<int,int> searchIn2dMatrixII(vector<vector<int>>mat,int target){
int rows=mat.size();
int cols=mat[0].size();
int r=0,c=cols-1;
while (r<rows && c>=0)
{
    if(mat[r][c]==target){
        return {r,c};
    }
    else if(mat[r][c]<target){
        r++;
    }else{
        c--;
    }
}
return {-1,-1};
}
int main()
{
vector<vector<int>>matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
int target;
cin>>target;
pair<int,int>ans=searchIn2dMatrixII(matrix,target);
cout<<ans.first<<","<<ans.second<<endl;
return 0;
}