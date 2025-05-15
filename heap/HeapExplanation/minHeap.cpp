#include <iostream>
#include <vector>
using namespace std;

// MinHeap Class
class MinHeap {
    vector<int> heap;

    // Helper function to heapify up from the index i
    void heapifyUp(int i) {
        if (i && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            heapifyUp((i - 1) / 2);
        }
    }

    // Helper function to heapify down from the index i
    void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Function to insert an element into the heap
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    // Function to extract the minimum element (root) from the heap
    int extractMin() {
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
    MinHeap minHeap;

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(6);
    minHeap.insert(1);
    minHeap.insert(8);

    cout << "Min Heap: ";
    minHeap.display();

    cout << "Extracting min: " << minHeap.extractMin() << endl;
    
    cout << "Min Heap after extraction: ";
    minHeap.display();

    return 0;
}
