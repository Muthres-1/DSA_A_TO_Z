#include<iostream>
#include<vector>
using namespace std;

// Brute Force approach
vector<int> firstAndLastOccurence(int target,int arr[],int length){
    vector<int>ans;
    int first=-1,last=-1;
    for(int i=0;i<length;i++){
       if(arr[i]==target){
        if(first==-1){
            first=i;
            last=i;
        }
        if(last!=-1){
            last=i;
        }
       }
    }
    ans.push_back(first);
    ans.push_back(last);
    return ans;    
}

// Optimize usign Binary Search 
// LowerBound=first
// UpperBound-1=second       
// This scenerio doesn't consider all cases  like when element doesn't available in the array 
// lowerBound(x)==n || arr[lb]!=x
// int upper_bound(int target,int arr[],int length){
//     int left=0;
//     int right=length-1;
//     int ans=-1;
//     while (left<=right)
//     {
//         int mid=left+(right-left)/2;// to resolve overflow problem
//         if(arr[mid]<=target){
//             ans=mid;
//             left=mid+1;
//         }
//         else// because the mid is not possible as answer 
//         {
//             left=mid-1;
//         }                
//     }
//     return ans;
// }


// int findLowerBound(int target,int arr[],int length){
//     int left=0;
//     int right=length-1;
//     int ans=length;
//     while (left<=right)
//     {
//         int mid=left+(right-left)/2;// to resolve overflow problem
//         if(arr[mid]>=target){
//             ans=mid;
//             right=mid-1;
//         }
//         else// because the mid is not possible as answer 
//         {
//             right=mid+1;
//         }
                
//     }
    
//     return ans;
// }

int firstOccurence(int target,int arr[],int length){
    int left=0,right=length-1;
    int first=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            first=mid;
            right=mid-1;
        }
        else if (arr[mid]>target)
        {
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return first;
}

int lastOccurence(int target,int arr[],int length){
    int left=0,right=length-1;
    int second=length;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            second=mid;
            right=mid+1;
        }
        else if (arr[mid]>target)
        {
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return second;
}

int main()
{
    int length=5;
    int arr[]={1,2,3,4,2};
    int target;
    cin>>target;
    vector<int>ans=firstAndLastOccurence(target,arr,5);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    // int first=findLowerBound(target,arr,length),second;
    // if(first!=length || arr[first]!=target){
    //     first=-1;
    //     second=-1;
    // }else{
    //     second=upper_bound(target,arr,5);
    // }
    // cout<<first<<" "<<second<<endl;
    int first=firstOccurence(target,arr,length),second;
    if(first==-1)cout<<-1<<" "<<-1<<endl;
    else{
        second=lastOccurence(target,arr,length);
    }
    cout<<first<<" "<<second<<endl;
    return 0;
}
