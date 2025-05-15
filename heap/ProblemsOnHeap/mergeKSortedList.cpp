#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
// Brute force 
// Time Complexity: O(N log N)
// Space Complexity: O(N) for storing the values.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        for (ListNode* list : lists) {
            while (list) {
                values.push_back(list->val);
                list = list->next;
            }
        }
        sort(values.begin(), values.end());
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int value : values) {
            curr->next = new ListNode(value);
            curr = curr->next;
        }
        
        return dummy->next;
    }
    // Optimization using min heap
    // Time Complexity: O(N log k), where N is the total number of nodes, and k is the number of lists.
   // Space Complexity: O(k) for the heap.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node value
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Initialize the heap with the head of each list
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* node = minHeap.top();
            minHeap.pop();
            curr->next = node;
            curr = curr->next;
            
            // If there is a next node in the same list, push it to the heap
            if (node->next) {
                minHeap.push(node->next);
            }
        }
        
        return dummy->next;
    }
    // More Optimization using divide and conquer 
    // Time Complexity: O(N log k), where N is the total number of nodes, and k is the number of lists.
   // Space Complexity: O(log k) due to recursion stack.
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeKListsHelper(lists, left, mid);
        ListNode* l2 = mergeKListsHelper(lists, mid + 1, right);
        
        return mergeTwoLists(l1, l2);
    }
};

int main() {
    Solution sol;
    // Example usage:
    vector<ListNode*> lists;
    // Add code to initialize your linked lists here...
    
    ListNode* result = sol.mergeKLists(lists);
    // Add code to print or process the result...
    
    return 0;
}
