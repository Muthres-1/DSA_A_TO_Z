#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Swap function to swap elements at index a and b
    void swap(vector<int>& stones, int a, int b) {
        int temp = stones[a];
        stones[a] = stones[b];
        stones[b] = temp;
    }

    // Function to heapify down from index i in a heap of size n
    void heapifyDown(vector<int>& stones, int i, int n) {
        int left = 2 * i + 1;  // left child index
        int right = 2 * i + 2; // right child index
        int largest = i;

        // Compare with left child
        if (left < n && stones[largest] < stones[left]) {
            largest = left;
        }
        
        // Compare with right child
        if (right < n && stones[largest] < stones[right]) {
            largest = right;
        }

        // If the largest is not the current node, swap and heapify down recursively
        if (largest != i) {
            swap(stones, largest, i);
            heapifyDown(stones, largest, n);  // Continue heapifying down
        }
    }

    // Function to get the last stone weight
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        // Build the max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(stones, i, n);
        }

        // Process the stones
        while (stones.size() > 1) {
            int n = stones.size();

            // Extract the two largest stones
            int a = stones[0]; // Largest stone (root of the heap)
            stones[0] = stones[n - 1]; // Move the last element to the root
            stones.pop_back();
            heapifyDown(stones, 0, stones.size()); // Re-heapify to maintain max heap

            int b = stones[0]; // Second largest stone
            stones[0] = stones[stones.size() - 1]; // Move last element to the root
            stones.pop_back();
            heapifyDown(stones, 0, stones.size()); // Re-heapify to maintain max heap

            // If the two stones are not equal, the remainder is pushed back into the heap
            if (a != b) {
                int remainder = abs(a - b);
                stones.push_back(remainder); // Add the remainder back to the heap
                int i = stones.size() - 1; // Index of the newly added element
                
                // Heapify up the new element to maintain max heap
                while (i > 0 && stones[(i - 1) / 2] < stones[i]) {
                    swap(stones, (i - 1) / 2, i);
                    i = (i - 1) / 2;
                }
            }
            // if a==b then no need to insert anything already destroyed and heapified
        }

        // Return the last stone or 0 if no stones are left
        return stones.empty() ? 0 : stones[0];
    }
};
