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

// Array is given as sorted 

// Brute force approach 
void removeDuplicateFromSA(vector<int>&arr,int length){
set<int>st;
for (auto it : arr)
{
    st.insert(it);
}
arr.clear();
for (auto it : st)
{
    arr.push_back(it);
}
}

// The time complexity is O(nlog2(n) + n) and space complexity is O(n)
void removeDuplicateFromSA2(vector<int>&arr,int length){
set<int>st;
for (auto it : arr)
{
    st.insert(it);
}
int ind=0;
for (auto it : st)
{
    arr[ind]=it;
    ind++;
}
}

// Optimized way
int removeDuplicateFromSAOptimized(vector<int>&arr,int length){
int i=0;
for (int  j = 1; j < length; j++)
{
    if(arr[j]!=arr[i]){
      arr[i+1]=arr[j];
      i++;
    }
}
return i+1;
}
int main()
{
vector<int>arr={1,2,2,3,3,4,5,6,6,7};
for (auto it : arr)
{
    cout<<it<<" ";
}
cout<<endl;
int n = arr.size();
// removeDuplicateFromSA(arr,n);
// removeDuplicateFromSA2(arr,n);
n = removeDuplicateFromSAOptimized(arr,n);
for (int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}