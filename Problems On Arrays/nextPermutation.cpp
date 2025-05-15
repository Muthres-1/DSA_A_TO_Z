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

// Brute force solution 
// Generate all permutation in sorted order 
// find our permutation place 
// and return next permutation if no next then return first one 
// This brute force way will take O(n!*n) which is very large time 

// better way using stl
vector<int> nextPermutation(vector<int>arr){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

// Optimized way 
// The time complexity is O(3*n) And the space complexity is O(1)
void nextPermutationOptimal(vector<int>&arr,int length){
    int ind=-1;
    for (int i = length-2; i >= 0; i--)
    {
        if (arr[i] < arr[i+1])
        {
            ind = i;
            break;
        }
        
    }
    if (ind == -1)
    {
        reverse(arr.begin(),arr.end());
        return;
    }
    for (int i = length-1; i > ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i],arr[ind]);
            break;
        }
        
    }
    reverse(arr.begin() + ind + 1,arr.end());
}
int main()
{
vector<int>arr={3,1,2};
vector<int>ans;
// ans=nextPermutation(arr);
nextPermutationOptimal(arr,arr.size());
for(auto it: arr){
    cout<<it<<" ";
}
cout<<endl;
return 0;
}