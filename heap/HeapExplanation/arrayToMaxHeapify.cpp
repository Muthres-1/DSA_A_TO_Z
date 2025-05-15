#include <iostream>
#include <vector>
using namespace std;

// Helper function to heapify a subtree with root at index i in a Max Heap
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

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

// Function to build a Max Heap from an array
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to display the heap
void displayHeap(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};

    cout << "Original array: ";
    displayHeap(arr);

    buildMaxHeap(arr);

    cout << "Array after converting to Max Heap: ";
    displayHeap(arr);

    return 0;
}
