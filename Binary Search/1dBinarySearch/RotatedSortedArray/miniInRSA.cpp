#include<iostream>
#include<vector>
using namespace std;

// This is also for non-Duplicates
int minimumInRSA(vector<int>arr,int length){
int left=0,right=length-1,ans=1e9;
while (left<=right)
{
    int mid=left+(right-left)/2;
    if (arr[left]<=arr[mid])// this ensure that left half is sorted 
    {
        ans=min(ans,arr[left]);
        left=mid+1;   
    }
    else// this says that left half is not sorted 
    {
        ans=min(ans,arr[mid+1]);
        right=mid-1;
    }
}
return ans;
}

int minimumInRSA2(vector<int>arr,int length){
int left=0,right=length-1,ans=1e9;
while (left<=right)
{
    int mid=left+(right-left)/2;
    if(arr[left]<=arr[right]){// when entire array is sorted then don't go for further 
        ans=min(ans,arr[left]);
        break;
    }
    if (arr[left]<=arr[mid])// this ensure that left half is sorted 
    {
        ans=min(ans,arr[left]);
        left=mid+1;   
    }
    else// this says that left half is not sorted 
    {
        ans=min(ans,arr[mid+1]);
        right=mid-1;
    }
}
return ans;
}
int main()
{
vector<int>arr={7,8,9,1,2,3,4,5,6};
cout<<minimumInRSA(arr,arr.size())<<endl;
cout<<minimumInRSA2(arr,arr.size())<<endl;
return 0;
}