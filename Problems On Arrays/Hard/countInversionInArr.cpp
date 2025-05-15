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

// Problem :- count the number of inversion such that in any pair left element is greater than right 
// for example [1,3,2] here (3,2) is an inversion pair but not (1,3) or (1,2)

// Brute force way 
// the time complexity is somewhere near about O(n^2) and space complexity is O(1)
int countInversion(vector<int>arr,int length){
    int cnt=0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (arr[i]>arr[j])
            {
                cnt++;
            }
            
        }
        
    }
    return cnt;
}

// Better way

// The time complexity is O(nlog2(n)) and space complexity is O(n)
int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt=0;
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
            cnt+=(mid-left+1);
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
    return cnt;
}
int divideAndMerge(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = low + (high - low) / 2;
    cnt +=divideAndMerge(arr, low, mid);
    cnt +=divideAndMerge(arr, mid + 1, high);
    cnt +=merge(arr, low, mid, high);
    return cnt;
}
int mergeSortAlgo(vector<int> &arr, int length)
{
    return divideAndMerge(arr, 0, length - 1);
}
int countInversionBetter(vector<int>arr,int length){
    return mergeSortAlgo(arr,arr.size());
    
}

int main()
{
//vector<int>arr={};

return 0;
}