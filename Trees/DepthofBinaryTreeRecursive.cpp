#include <iostream>
#include <algorithm> 

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
    int maxDepth(TreeNode* root) {
        // Base case: if the tree is empty, the depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The depth of the current node is the maximum of the depths of the subtrees plus one
        return max(leftDepth, rightDepth) + 1;
    }
};

// Helper function to print the result
void printDepth(Solution& solution, TreeNode* root) {
    int depth = solution.maxDepth(root);
    cout << "Depth of the tree: " << depth << endl;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    cout << "Tree 1: ";
    printDepth(solution, root1);

    // Example 2
    TreeNode* root2 = nullptr;
    cout << "Tree 2: ";
    printDepth(solution, root2);

    return 0;
}
