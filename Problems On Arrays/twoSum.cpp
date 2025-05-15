#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

// Brute force approach
pair<int, int> twoSum(vector<int> arr, int k)
{
    int length = arr.size();
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
// pair<int,int> twoSum2(vector<int>arr,int k){
//     int count=0;
//     int sum=0;
//     int length=arr.size();
//     for (int i = 0; i < length; i++)
//     {
//         count++;
//         sum=arr[i];
//         for (int j = i+1; j < length; j++)
//         {
//             count++;
//             sum+=arr[j];
//              if(sum ==k && count = 2)
//              {
//                 return {i,j};
//              }

//         }

//     }
//     return {-1,-1};
// }

// Better way
// The time complexity is O(nlog(n)) and space complexity is O(n)
// If we use unordered_map then it can go to O(n^2) and best And average case is O(n)
pair<int, int> twoSumBetter(int n, vector<int> arr, int target)
{
    map<int, int> mp; // array store indexes as key but here we are storing value as key
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more = target - a;
        if (mp.find(more) != mp.end())
        {
            return {mp[more], i};
        }
        mp[a] = i;
    }
    return {-1, -1};
}

// get rid of space complexity using two pointer
string twoSumOptimized(vector<int> arr, int length, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = length - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return "NO";
}

int main()
{
    vector<int> arr = {1, 5, 2, 7, 3};
    int k;
    cin >> k;
    pair<int, int> ans;
    // ans= twoSum2(arr,k);
    // cout<<ans.first << " " <<ans.second<<endl;
    // ans = twoSumBetter(arr.size(),arr,k);
    // cout<<ans.first <<" " <<ans.second<<endl;
    string str = twoSumOptimized(arr, arr.size(), k);
    cout <<str<< endl;
    return 0;
}