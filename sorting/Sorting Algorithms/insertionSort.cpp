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

// It takes an element and put that to its actual position

// The time complexity is O(n^2) for worst and average case
// and for best case time complexity is O(n) when array is already sorted

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        // Mtlb jitne bhi bde h unn sabko aage shift kar diya
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};
    insertionSort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}