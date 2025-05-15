#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap
    
    // Add the first k+1 elements into the heap
    for (int i = 0; i <= k && i < arr.size(); i++) {
        minHeap.push(arr[i]);
    }
    
    int index = 0;  // To place the sorted elements in the array
    
    // Process the remaining elements
    for (int i = k + 1; i < arr.size(); i++) {
        // Extract the minimum element from the heap
        arr[index++] = minHeap.top();
        minHeap.pop();
        
        // Add the current element into the heap
        minHeap.push(arr[i]);
    }
    
    // Place the remaining elements from the heap into the array
    while (!minHeap.empty()) {
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
}

   
int main() {
    
    // for single array 

    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;  // The array is 3-sorted
    
    sortKSortedArray(arr, k);
    
    // Print the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    
    
    return 0;
}



