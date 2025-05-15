#include <iostream>
#include <vector>
using namespace std;

// MaxHeap Class
class MaxHeap {
    vector<int> heap;

    // Helper function to heapify up from the index i
    void heapifyUp(int i) {
        if (i && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            heapifyUp((i - 1) / 2);
        }
    }

    // Helper function to heapify down from the index i
    void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Function to insert an element into the heap
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    // Function to extract the maximum element (root) from the heap
    int extractMax() {
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    // Function to display the heap
    void display() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

// Example usage
int main() {
    MaxHeap maxHeap;
    
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(6);
    maxHeap.insert(1);
    maxHeap.insert(8);

    cout << "Max Heap: ";
    maxHeap.display();

    cout << "Extracting max: " << maxHeap.extractMax() << endl;
    
    cout << "Max Heap after extraction: ";
    maxHeap.display();

    return 0;
}

// Conclusion
// Time Complexity : O(N)
// Auxiliary space: O(1) (since heapify operates in-place).
// Call stack space: O(log N) due to the depth of recursive calls being bounded by the height of the heap.