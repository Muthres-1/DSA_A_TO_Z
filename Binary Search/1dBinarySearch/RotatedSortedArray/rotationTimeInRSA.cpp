#include<iostream>
#include<vector>

using namespace std;

int rotationInRSA(vector<int>arr,int length){
int left=0,right=length-1,ans=1e9,index=-1;
while (left<=right)
{
    int mid=left+(right-left)/2;
    if(arr[left]<=arr[right]){// when entire array is sorted then don't go for further 
        if(arr[left]<ans){
        ans=arr[left];
        index=left;
    }
    break;
    }
    if (arr[left]<=arr[mid])// this ensure that left half is sorted 
    {
        if(arr[left]<ans){
            ans=arr[left];
            index=left;
        }
        left=mid+1;   
    }
    else// this says that left half is not sorted 
    {
        if(arr[mid+1]<ans){
            ans=arr[mid+1];
            index=mid+1;
        }
        right=mid-1;
    }
}
return index;
}
int main()
{
vector<int>arr={3,4,5,1,2}; // This is rotated 3 times 
cout<<rotationInRSA(arr,arr.size())<<endl;
return 0;
}