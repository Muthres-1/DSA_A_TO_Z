#include<iostream>
using namespace std;
// What is Upper Bound?
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index 
// is greater than the given key i.e. x.
// The upper bound is the smallest index, ind, where arr[ind] > x.
// Here we checked two condition in first if and rest is only one condition is in else case 
int upper_bound(int target,int arr[],int length){
    int left=0;
    int right=length-1;
    int ans=-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;// to resolve overflow problem
        if(arr[mid]>target){
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

int main()
{
    int arr[]={1,2,3,4};
    int target;
    cin>>target;
    cout<<upper_bound(target,arr,4)<<endl;
return 0;
}

