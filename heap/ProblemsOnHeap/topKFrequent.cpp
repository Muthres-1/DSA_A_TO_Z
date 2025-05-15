#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<queue>
using namespace std;
// Brute Force Approach
// Time Complexity:
// Counting frequencies: O(n)
// Sorting based on frequency: O(n log n)
// Overall: O(n log n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Frequency map
    unordered_map<int, int> freq_map;
    for (int num : nums) {
        freq_map[num]++;
    }

    // Step 2: Create a vector of elements
    vector<pair<int, int>> freq_vector(freq_map.begin(), freq_map.end());

    // Step 3: Sort elements by frequency in descending order
    sort(freq_vector.begin(), freq_vector.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    });

    // Step 4: Pick top k elements
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(freq_vector[i].first);
    }

    return result;
}

// Optimal Approach 
// Time Complexity:
// Counting frequencies: O(n)
// Building a heap of size k: O(n log k)
// Overall: O(n log k)
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Frequency map
    unordered_map<int, int> freq_map;
    for (int num : nums) {
        freq_map[num]++;
    }

    // Step 2: Min-heap to store top k elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for (auto& [num, freq] : freq_map) {
        min_heap.push({freq, num});
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // Step 3: Extract top k elements from the heap
    vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }

    return result;
}

// Further more optimization
// Thus, the total time complexity is:
// O(N) for the frequency count.
// O(N) for building the heap (heapify).
// O(k log N) for extracting the k elements.
// Thus, the overall complexity is O(N + k log N).
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Frequency map
    unordered_map<int, int> freq_map;
    for (int num : nums) {
        freq_map[num]++;
    }

    // Step 2: Use a max-heap to store elements by frequency
    priority_queue<pair<int, int>> max_heap;
    for (auto& [num, freq] : freq_map) {
        max_heap.push({freq, num});  // (frequency, element)
    }

    // Step 3: Extract top k elements from the heap
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(max_heap.top().second);
        max_heap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
