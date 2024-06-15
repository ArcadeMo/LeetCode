#include <iostream>
#include <algorithm> // For std::max

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }

private:
    // Function to check the balance of the tree and calculate height utilizing DFS
    pair<bool, int> checkBalance(TreeNode* node) {
        // Base case: if the node is nullptr, it is balanced and its height is 0
        if (node == nullptr) {
            return {true, 0};
        }

        // Recursively check the balance and height of the left and right subtrees
        auto left = checkBalance(node->left);
        auto right = checkBalance(node->right);

        // Check if the current node is balanced
        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;
        
        // Calculate the height of the current node
        int height = max(left.second, right.second) + 1;

        // Return whether the subtree rooted at the current node is balanced and its height
        return {balanced, height};
    }
};

// Helper function to print the result
void printIsBalanced(Solution& solution, TreeNode* root) {
    bool isBalanced = solution.isBalanced(root);
    cout << "Tree is " << (isBalanced ? "balanced" : "not balanced") << endl;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    cout << "Tree 1: ";
    printIsBalanced(solution, root1);

    // Example 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(4);
    root2->right->left->left = new TreeNode(5);
    cout << "Tree 2: ";
    printIsBalanced(solution, root2);

    // Example 3
    TreeNode* root3 = nullptr;
    cout << "Tree 3: ";
    printIsBalanced(solution, root3);

    return 0;
}
