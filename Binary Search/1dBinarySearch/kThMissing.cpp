#include<iostream>
#include<vector>

using namespace std;

int kThMissingNumber(vector<int>arr,int k){
int low=0,high=arr.size()-1;
while (low<=high)
{
    int mid=low+(high-low)/2;
    int missing=arr[mid]-(mid+1);
    if(missing<k){
        low=mid+1;
    }else{
        high=mid-1;
    }
}
return (high+k+1); // or (low+k); or missing=arr[high]-(high+1)) arr[high]+more =>more=k-missing ,low=high+1
}
int main()
{
vector<int>arr={2,3,4,7,10};
int k;
cin>>k;
cout<<kThMissingNumber(arr,k);
return 0;
}