#include <bits/stdc++.h>

using namespace std;

// Brute force approach 
// Time Complexity:
// addNum: O(1) (average case)
// findMedian: O(N log N) (due to sorting)
// Space Complexity: O(N) to store the numbers.
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        nums.push_back(num);
    }

    double findMedian() {
        sort(nums.begin(), nums.end()); // Sort the list to find the median
        int n = nums.size();
        if (n % 2 == 0) {
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        } else {
            return nums[n / 2];
        }
    }

private:
    vector<int> nums; // Store the numbers
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2
    return 0;
}

// Optimized solution 
// Time Complexity:
// addNum: O(log N) (for insertion and balancing the heaps)
// findMedian: O(1) (constant time to access the tops of the heaps)
// Space Complexity: O(N) for storing the elements in the heaps
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num); // Add to max heap
        // Ensure the largest element in maxHeap is less than or equal to the smallest in minHeap
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // Balance the sizes of the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }

private:
    priority_queue<int> maxHeap; // Max heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the upper half
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2
    return 0;
}


// Further Optimized: The same heap-based approach but with streamlined checks and balances.


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num); // Add to max heap
        
        // If the largest in maxHeap is greater than the smallest in minHeap
        if (maxHeap.size() > 0 && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }

private:
    priority_queue<int> maxHeap; // Max heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the upper half
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2
    return 0;
}
