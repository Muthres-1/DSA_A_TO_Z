#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index i for Min Heap
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;       // Initialize smallest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected subtree
        minHeapify(arr, n, smallest);
    }
}

// Function to perform Heap Sort in descending order using Min Heap
void heapSortDescending(vector<int>& arr) {
    int n = arr.size();

    // Build a Min Heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    // One by one extract elements from heap and place them at the end of the array
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call minHeapify on the reduced heap
        minHeapify(arr, i, 0);
    }
}

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    displayArray(arr);

    heapSortDescending(arr);

    cout << "Sorted array in descending order: ";
    displayArray(arr);

    return 0;
}
