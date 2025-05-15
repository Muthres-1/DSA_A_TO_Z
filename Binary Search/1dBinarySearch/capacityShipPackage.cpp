#include<iostream>
#include<vector>
using namespace std;

pair<int,int> SumAndMax(vector<int>arr){
    int total=0,maxi=-1e9;
    for (int i = 0; i < arr.size(); i++)
    {
        total+=arr[i];
        maxi=max(maxi,arr[i]);
    }
    return {total,maxi};
}
int requiredDays(vector<int>arr,int capasity){
    int load=0,days=1;
    for (int i = 0; i < arr.size(); i++)
    {
        if(load+arr[i]>capasity){
            days+=1;
            load=arr[i];
        }else{
            load+=arr[i];
        }
    }
    return days;
}
int capacityOfShip(vector<int>arr,int days){
    if(days==0)return -1;
    pair<int,int>a=SumAndMax(arr);
    int right=a.first;
    int left=a.second;
    int ans=right;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if(requiredDays(arr,mid)<=days){
            ans=mid;
            right=mid-1;        
        }else{
            left=mid+1;
        }
    }
    return ans;
}
int main()
{
vector<int>arr={1,2,3,4,5,6,7,8,9,10};
int days=5;
// cin>>days;
cout<<capacityOfShip(arr,days)<<endl;
return 0;
}