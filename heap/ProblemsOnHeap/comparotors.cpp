#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// [capture](parameters) -> return_type { body }
auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minHeap(comp);

auto comp2 = [](ListNode* a, ListNode* b) {
    return a->val < b->val;  // Max-Heap: larger elements are prioritized
};
priority_queue<ListNode*, vector<ListNode*>, decltype(comp2)> maxHeap(comp2);

int main()
{

return 0;
}