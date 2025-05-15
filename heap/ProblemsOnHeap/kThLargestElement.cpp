#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Heapify function to maintain the max-heap property
    void heapify(vector<int>& arr, int n, int index) {
        if (index >= n) return;
        
        int largest = index;
        int leftInd = 2 * index + 1;  // Left child index
        int rightInd = 2 * index + 2; // Right child index
        
        // If left child is larger than root
        if (leftInd < n && arr[largest] < arr[leftInd]) {
            largest = leftInd;
        }
        
        // If right child is larger than the largest so far
        if (rightInd < n && arr[largest] < arr[rightInd]) {
            largest = rightInd;
        }
        
        // If the largest is not root, swap and continue heapifying
        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to build a max heap
    void maxHeap(vector<int>& arr, int n) {
        int start = n / 2 - 1; // First non-leaf node
        for (int i = start; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    // Function to delete the top (max) element of the heap
    void deleteTop(vector<int>& arr, int n) {
        // Swap the first element (max) with the last element
        swap(arr[0], arr[n - 1]);
        // Heapify the root of the reduced heap
        heapify(arr, n - 1, 0);
    }

    // Function to find the k-th largest element
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        // Build max heap
        maxHeap(nums, size);
        
        // Remove the top of the heap k-1 times to get the k-th largest element
        for (int i = 0; i < k - 1; i++) {
            deleteTop(nums, size);
            size--; // Reduce the heap size
        }
        
        // The top of the heap now is the k-th largest element
        return nums[0];
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution sol;
    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "-th largest element is: " << result << endl;
    return 0;
}
