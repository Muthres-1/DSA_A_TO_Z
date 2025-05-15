#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;


void leftRotationByOne(vector<int>&arr,int length){
int previous=arr[0];
for(int i=length-1;i>=0;i--){
int curr=arr[i];
arr[i]=previous;
previous=curr;
}
}
// Brute force approach
// Time complexity is O(n*K) and extra space complexity is O(1)
void leftRotationByK(vector<int>&arr,int length,int k){
    k%=length;
    for (int i = 0; i < k; i++)
    {
        leftRotationByOne(arr,length);
    }
    
}

// Optimized way 
// The time complexity is O(n+k) And Extra space complexity is O(k)
void leftRotationByKBetter(vector<int>&arr,int length,int k){
    k%=length;
    vector<int>temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = k; i < length; i++)
    {
        arr[i-k]=arr[i];
    }
    for (int i = length-k; i < length; i++)
    {
        arr[i]=temp[i-(length-k)];
    }   
}

// the Optimized solution O(2*n) but the extra space complexity is O(1)

void reverse(vector<int>&arr,int low,int high){
    while (low<=high)
    {
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
       
}
void leftRotationByKOptimized(vector<int>&arr,int length,int k){
    reverse(arr,0,k-1);
    reverse(arr,k,length-1);
    reverse(arr,0,length-1);
}
int main()
{
vector<int>arr={1,2,3,4,5,6};
int length=arr.size();

int k;
cin>>k;
for(auto it : arr){
    cout<<it<<" ";
}
cout<<endl;

// leftRotationByK(arr,length,k);
// leftRotationByKBetter(arr,length,k);
leftRotationByKOptimized(arr,length,k);
for(auto it : arr){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}