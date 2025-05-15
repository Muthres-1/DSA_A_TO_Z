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

int maxSubArrSum(vector<int> arr, int length)
{
    int maxSum = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            int sum = 0;
            for (int k = i; i <= j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// better brute force approach

int maxSubArrSumBetter(vector<int> arr, int length)
{
    int maxSum = 0;
    for (int i = 0; i < length; i++)
    {
        int sum = 0;
        for (int j = i; j < length; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Optimized way
// Time complexity is O(n) and space complexity is O(1)
int kadanesAlgo(vector<int> arr, int length)
{
    int maxSum = 0;
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}
// Optimized way if we want to print also subArray
// Time complexity is O(n) and space complexity is O(1)
pair<int, int> kadanesAlgo2(vector<int> arr, int length)
{
    int maxSum = 0;
    int sum = 0;
    int ansStart = -1, ansEnd = -1,start = -1;
    for (int i = 0; i < length; i++)
    {
        if (sum == 0)
        {
            start = i;
        }

        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return {ansStart, ansEnd};
}
int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    // cout<<maxSubArrSum(arr,arr.size())<<endl;
    cout << kadanesAlgo(arr, arr.size()) << endl;
    return 0;
}
