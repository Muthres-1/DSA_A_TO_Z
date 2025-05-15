#include<iostream>
#include<vector>

using namespace std;

// In this we are supposed to be the array with non-duplicate elements
int searchInRotatedSortedArray(vector<int>arr,int length,int target){
    int left=0,right=length-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }// After this ensure that which half is sorted either left half or right half  And one of them will be sorted because it is rotated sorted array and we are compairing with mid of array and it doesn't have any duplicate elements inside of the array But in the case of duplicate it may not to be sorted because there may problem when arr[left]=arr[mid]=arr[right]
        else if (arr[left]<=arr[mid])// this ensure that left half is sorted 
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
vector<int>arr={7,8,9,1,2,3,4,5,6};
int target;
cin>>target;
cout<<searchInRotatedSortedArray(arr,arr.size(),target)<<endl;
return 0;
}