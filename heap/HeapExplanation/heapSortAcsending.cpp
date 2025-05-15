#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index i for Max Heap
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

// Function to perform Heap Sort in ascending order using Max Heap
void heapSortAscending(vector<int>& arr) {
    int n = arr.size();

    // Build a Max Heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    // One by one extract elements from heap and place them at the end of the array
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
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

    heapSortAscending(arr);

    cout << "Sorted array in ascending order: ";
    displayArray(arr);

    return 0;
}
