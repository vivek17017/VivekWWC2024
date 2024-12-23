#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to build the tree recursively
TreeNode* helper(const vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]); // Create node with the middle element

    // Recursively build the left and right subtrees
    root->left = helper(nums, left, mid - 1);   // Left subtree
    root->right = helper(nums, mid + 1, right); // Right subtree

    return root;
}

// Function to convert sorted array to a height-balanced BST
TreeNode* sortedArrayToBST(const vector<int>& nums) {
    // Start the recursive process with the whole array
    return helper(nums, 0, nums.size() - 1);
}

// Function to print the in-order traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);   // Traverse left subtree
    cout << root->val << " ";       // Print node value
    inorderTraversal(root->right);  // Traverse right subtree
}

int main() {
    // Example input: sorted array
    vector<int> nums = {-10, -3, 0, 5, 9};
    
    // Convert the sorted array to a height-balanced BST
    TreeNode* root = sortedArrayToBST(nums);
    
    // Print the in-order traversal of the resulting BST to verify the result
    cout << "In-order traversal of the resulting BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
