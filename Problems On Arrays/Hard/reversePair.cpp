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

// Problem :- left element should be greater than twice of right element 
// Brute force way 
// the time complexity is somewhere near about O(n^2) and space complexity is O(1)
int countInversion(vector<int>arr,int length){
    int cnt=0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (arr[i]>2*arr[j])
            {
                cnt++;
            }
            
        }
        
    }
    return cnt;
}

//  Optimal way
// The time complexity is O(2*nlog2(n)) and space complexity is O(n)
// int cnt = 0;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    // [low.....mid]
    // [mid+1....high]
    int left = low;
    int right = high + 1;
    while (left <= mid && right << high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int>&arr,int low,int mid,int high){
    int right =mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2*arr[right])right++;
        cnt+=right-(mid+1);
        
    }
    return cnt;
}
int divideAndMerge(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = low + (high - low) / 2;
    cnt+=divideAndMerge(arr, low, mid);
    cnt+=divideAndMerge(arr, mid + 1, high);
    cnt += countPairs(arr,low,mid,high);
    merge(arr, low, mid, high);
    return cnt;
}
int mergeSortAlgo(vector<int> &arr, int length)
{
    return divideAndMerge(arr, 0, length - 1);
}

int countInversionOptimal(vector<int>arr,int length){
    return mergeSortAlgo(arr,arr.size());
    
}
int main()
{
//vector<int>arr={};

return 0;
}