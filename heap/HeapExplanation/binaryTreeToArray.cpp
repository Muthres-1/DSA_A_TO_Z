#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Binary Tree Node Definition
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
vector<int> binaryTreeToArray(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }
    
    vector<int> array;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node) {
            array.push_back(node->value); // Add the current node's value to the array
            q.push(node->left);           // Add left child to the queue
            q.push(node->right);          // Add right child to the queue
        } else {
            array.push_back(-1);  // Use -1 to represent a NULL node
        }
    }
    
    // Remove trailing -1 (NULL) values to make it a compact array
    while (!array.empty() && array.back() == -1) {
        array.pop_back();
    }
    
    return array;
}
int main() {
    // Creating a binary tree (Linked List Representation)
    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   5   6
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    // Convert the tree to array representation
    vector<int> arrayRepresentation = binaryTreeToArray(root);
    
    // Output the array
    for (int val : arrayRepresentation) {
        cout << val << " ";
    }
    
    return 0;
}
