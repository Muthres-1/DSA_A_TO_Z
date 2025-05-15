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

// This algorithm takes minimum element from the remaining part and put it to at the front 
// The time complexity for best case,worst and average case is O(n^2)
void selectionSort(vector<int> &arr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < length; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = i;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    vector<int> arr = {3, 4, 2, 1, 4, 4, 3, 7, 6, 9};
    selectionSort(arr, arr.size());
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}