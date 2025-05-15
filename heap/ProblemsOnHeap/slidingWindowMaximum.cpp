#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


// Brute Force - Time Complexity: O(n * k)
// Optimized using Max-Heap (Priority Queue) - Time Complexity: O(n log k)
// Further Optimized using Deque - Time Complexity: O(n)
class Solution {
public:
// Brute force 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= nums.size() - k; ++i) {
            int max_val = nums[i];
            for (int j = i + 1; j < i + k; ++j) {
                max_val = max(max_val, nums[j]);
            }
            result.push_back(max_val);
        }
        return result;
    }
// Optimized using max heap
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Push the current element with its index into the heap
            maxHeap.push({nums[i], i});
            
            // Remove elements that are outside the current window
            while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }

            // Once the window has at least k elements, record the max element
            if (i >= k - 1) {
                result.push_back(maxHeap.top().first);
            }
        }
        
        return result;
    }
// further more optimized using queue
     vector<int> maxSlidingWindow3(vector<int>& nums, int k) {
        deque<int> dq;  // Store indices of the elements
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices of elements not within the window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove elements from the back of the deque if they are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add the current element's index to the deque
            dq.push_back(i);
            
            // Once we have processed the first k elements, we can start adding results
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
