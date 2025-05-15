#include <iostream>
#include <vector>
using namespace std;

// Helper function to heapify a subtree with root at index i in a Min Heap
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

// Function to build a Min Heap from an array
void buildMinHeap(vector<int>& arr) {
    int n = arr.size();

    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
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

    buildMinHeap(arr);

    cout << "Array after converting to Min Heap: ";
    displayHeap(arr);

    return 0;
}
