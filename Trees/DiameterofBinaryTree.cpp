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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Initialize the diameter to zero
        height(root, diameter); // Call the height function to calculate the height and update the diameter
        return diameter; // Return the calculated diameter
    }

private:
    // Height function that utilizing depth first search to calculate the height of the tree and update the diameter
    int height(TreeNode* node, int &diameter) {
        // Base case: if the current node is nullptr, return zero as the height
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        // Update the diameter if the sum of left and right subtree is larger than the current diameter
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node which is the greatest height of the left and right subtree plus 1
        return max(leftHeight, rightHeight) + 1;
    }
};

void printDiameter(Solution& solution, TreeNode* root) {
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the tree: " << diameter << endl;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    root1->right->right = new TreeNode(4);
    root1->right->left->right = new TreeNode(5);
    cout << "Tree 1: ";
    printDiameter(solution, root1);

    // Example 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout << "Tree 2: ";
    printDiameter(solution, root2);

    return 0;
}