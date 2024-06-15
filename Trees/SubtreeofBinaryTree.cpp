#include <iostream>

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If subRoot is nullptr, it is always a subtree
        if (!subRoot) return true;
        // If root is nullptr, subRoot cannot be a subtree
        if (!root) return false;

        // If trees rooted at root and subRoot are the same, return true
        if (isSameTree(root, subRoot)) return true;

        // Otherwise, recursively check if subRoot is a subtree of either left or right subtree of root
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        // If both nodes are nullptr, they are the same
        if (!s && !t) return true;
        // If one of the nodes is nullptr, they are not the same
        if (!s || !t) return false;
        // If the values of the nodes are different, they are not the same
        if (s->val != t->val) return false;
        // Recursively check if left and right subtrees are the same
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};

// Helper function to print the result
void printIsSubtree(Solution& solution, TreeNode* root, TreeNode* subRoot) {
    bool isSub = solution.isSubtree(root, subRoot);
    cout << "The subtree is " << (isSub ? "found" : "not found") << endl;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    TreeNode* subRoot1 = new TreeNode(2);
    subRoot1->left = new TreeNode(4);
    subRoot1->right = new TreeNode(5);
    cout << "Example 1: ";
    printIsSubtree(solution, root1, subRoot1);

    // Example 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->left->left->left = new TreeNode(6);
    TreeNode* subRoot2 = new TreeNode(2);
    subRoot2->left = new TreeNode(4);
    subRoot2->right = new TreeNode(5);
    cout << "Example 2: ";
    printIsSubtree(solution, root2, subRoot2);

    return 0;
}
