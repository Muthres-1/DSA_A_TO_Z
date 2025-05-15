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

// The time complexity for the perticular algorithm is O(nlog2(n)) and the space complexity is  O(1)
// here we will any pivot and then less than equal to pivot will be left and greater than pivot will be
// right of pivot 
// for that we swap the first element which greater than pivot from the side of left and less than pivot from right 
// and then swap both and at the end j will cross i such that arr[j]<=pivot and arr[i]>pivot 
// so the j th position is the right place of pivot
void swap(vector<int> &arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j); // j ke sath isliye bcz j will cross the i and 
    return j;
}
void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}
vector<int> quickSortAlgo(vector<int> &arr, int length)
{
    qs(arr, 0, length - 1);
    return arr;
}
int main()
{
    vector<int> arr = {3, 4, 2, 1, 4, 4, 3, 7, 6, 9};
    quickSortAlgo(arr, arr.size());
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}