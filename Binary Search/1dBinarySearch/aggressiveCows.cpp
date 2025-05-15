#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// This is kind of max of min
bool canWePlace(vector<int>arr,int dist,int cows,int length){
    int countCows=1,lastCoOrdinate=arr[0];
    for (int i = 0; i < length; i++)
    {
       if(arr[i]-lastCoOrdinate>=dist){
        countCows++;
        lastCoOrdinate=arr[i];
       }   
       if(countCows>=cows)return true;
    }
    return false;    
}
// Brute force approach
int maxOfMinDistanceCows(vector<int>arr,int length, int cows){
    if(cows<=1)return -1;
    sort(arr.begin(),arr.end());
    int min=arr[0],max=arr[length-1];
    for(int i=1;i<=(max-min);i++){
    if(canWePlace(arr,i,cows,length)==true){
        if(i==(max-min))return i;
        continue;
    }else{
        return i-1;
    }
    }
    return -1;
}

// Optimized Way
int maxOfMinDistanceCowsOptimized(vector<int>arr,int length, int cows){
    if(cows<2)return -1;
    sort(arr.begin(),arr.end());
    int min=arr[0],max=arr[length-1];
    int left=1,right=max-min,ans=-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if(canWePlace(arr,mid,cows,length)){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return ans; // we can return high also instead of ans
}
int main()
{
vector<int>arr={0,3,4,7,9,10};
int cows;
cin>>cows;
cout<<maxOfMinDistanceCows(arr,arr.size(),cows)<<endl;
cout<<maxOfMinDistanceCowsOptimized(arr,arr.size(),cows)<<endl;
return 0;
} 