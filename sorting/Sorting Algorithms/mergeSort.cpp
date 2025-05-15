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


// The time complexity is O(nlog2(n)) and space complexity is O(n)
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
void divideAndMerge(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    divideAndMerge(arr, low, mid);
    divideAndMerge(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void mergeSortAlgo(vector<int> &arr, int length)
{
    divideAndMerge(arr, 0, length - 1);
}
int main()
{
    vector<int> arr = {3, 4, 2, 1, 4, 4, 3, 7, 6, 9};
    mergeSortAlgo(arr, arr.size());
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

