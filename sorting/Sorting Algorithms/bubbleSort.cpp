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

// This algorithm takes larger element and put it end of remaining part
// The time complexity for the algorithm is = O(n^2) for average and worst case and 
// for best case the time complexity is O(n) when array is already sorted
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: stop if already sorted
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    bubbleSort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}