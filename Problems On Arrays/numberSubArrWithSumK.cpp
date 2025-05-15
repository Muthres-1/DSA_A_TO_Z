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

// this is number of subarr earlier we saw the longest subarr with sum = k
// Brute force way
// time complexity is nearAbout O(n^3)
int NmsOfSubArrWithSumK(vector<int> arr, int length, int target)
{
    int cnt = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == target)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
// Better way
// time complexity is nearAbout O(n^2)
int NmsOfSubArrWithSumKBetter(vector<int> arr, int length, int target)
{
    int cnt = 0;
    for (int i = 0; i < length; i++)
    {
        int sum = 0;
        for (int j = i; j < length; j++)
        {
            sum+=arr[j];
            if (sum == target)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

// Optimal way
int NmsOfSubArrWithSumKOptimal(vector<int> arr, int length, int target)
{
    int left = 0, right = 0;
    long long sum = arr[0];
    int cnt=0;
    while (right < length)
    {
        while (left <= right && sum>target)
        {
            sum-=arr[left];
            left++;
            if (sum == target)
            {
                cnt++;
            }
        }
        if (sum == target)
        {
            cnt++;
        }
        right++;
        if (right < length)
        {
            sum+=arr[right];
        }
        
    }
    return cnt;
}

// Optimal way
// O(n*log(n)) and if we use unordered_map then O(n) for best and average and for worst O(n*2) and the space comeplexity O(N)
// Very Important solution of prefix sum
int NmsOfSubArrWithSumKOptimal2(vector<int> arr, int length, int target)
{
  map<int,int>mpp;
  mpp[0]=1;   
  int preSum = 0 , cnt =0;
  for (int i = 0; i < length; i++)
  {
    preSum+=arr[i];
    int remove = preSum-target;
    cnt+=mpp[remove];
    mpp[preSum]+=1;
  }
  return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1,1,4, 2, -3};
    int k;
    cin >> k;
    cout << NmsOfSubArrWithSumK(arr, arr.size(), k) << endl;
    cout << NmsOfSubArrWithSumKBetter(arr, arr.size(), k) << endl;
    cout << NmsOfSubArrWithSumKOptimal2(arr, arr.size(), k) << endl;
    return 0;
}