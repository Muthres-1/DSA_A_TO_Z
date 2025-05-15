#include<iostream>
#include<vector>

using namespace std;

// The important thing 
// Here the output need not to be first element for example 
// 2 3 3 4 here output need not to be 1 it may come 2 also 
int searchInRotatedSortedArrayWithDuplicate(vector<int>arr,int length,int target){
int left=0,right=length-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]==arr[left] && arr[mid]==arr[right]){
            left+=1;
            right-=1;
            continue;
        }
        if (arr[left]<=arr[mid])// this ensure that left half is sorted 
        {
            if(target>=arr[left] && target<=arr[mid] ){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        else// this says that left half is not sorted 
        {
            if(target>=arr[mid] && target<=arr[right])
            {
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
    return -1;    
}
int main()
{
vector<int>arr={3,8,1,2,3,3,3,4,5,3};
int target;
cin>>target;
cout<<searchInRotatedSortedArrayWithDuplicate(arr,arr.size(),target)<<endl;
return 0;
}