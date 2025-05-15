#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// Brute force approach :- start from k=1 and check it possibility and if not then go till minimum possible value of k
// Optimal answer
int hrsTaken(vector<int>arr,int k){
    int total=0;
    for(int i=0;i<arr.size();i++){
        total+=ceil(double(arr[i])/double(k));
    }
    return total;
}

int findMaxi(vector<int>arr){
    int maxi=-1e9;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
int bananasPerHrs(vector<int>arr,int hrs){
    int left=1;
    int maxi=findMaxi(arr);
    int right=maxi;
    int ans=right;
    while (left<=right)
    {
        int mid=left+ (right-left)/2;
        int total=hrsTaken(arr,mid);
        if(total<=hrs){
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
vector<int> arr={3,6,7,11};
int deadline=8;

// cin>>deadline;
cout<<bananasPerHrs(arr,deadline)<<endl;
return 0;
}