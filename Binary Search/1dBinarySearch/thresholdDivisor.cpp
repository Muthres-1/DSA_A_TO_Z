#include<iostream>
#include<vector>
using namespace std;

pair<int,int> findMaxiAndSum(vector<int>arr){
    int maxi=-1e9,mini=1e9,total=0;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
        total+=arr[i];
    }
    return {maxi,total};
}

int IsPossible(vector<int>arr,int mid){
    int total=0;
    for (int i = 0; i < arr.size(); i++)
    {
        total+=ceil(double(arr[i])/double(mid));
    }
    return total;    
}
int findThresholdDivisor(vector<int>arr,int threshold){
    pair<int,int>a=findMaxiAndSum(arr);
    int total=a.second;
    if(total<threshold)return -1;
    int high=a.first;
    int low=1;
    int ans=low;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(IsPossible(arr,mid)<=threshold){
          ans=mid;
          high=mid-1;
        }
        low=mid+1;
    }
    return ans;
}
int main()
{
    vector<int>arr={1,10,3,10,2};
    int threshold;
    cin>>threshold;
    cout<<findThresholdDivisor(arr,threshold);
    return 0;
}