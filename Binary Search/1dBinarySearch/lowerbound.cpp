#include<iostream>
using namespace std;
// What is Lower Bound?
// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that 
// index is greater than or equal to a given key i.e. x.
// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
// Here we checked two condition in first if and rest is only one condition is in else case 
int findLowerBound(int target,int arr[],int length){
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
int main()
{
    int arr[]={1,2,2,3,4};
    int target;
    cin>>target;
    cout<<findLowerBound(target,arr,4)<<endl;
return 0;
}