#include <iostream>
#include <queue>
#include <vector>

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
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the tree is empty, return nullptr
        if (root == nullptr) {
            return nullptr;
        }

        // Recursively invert the left and right subtrees
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        // Swap the left and right children of the current node
        root->left = right;
        root->right = left;

        // Return the root of the inverted tree
        return root;
    }
};

// Helper function to print the binary tree level by level
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    vector<string> result;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Remove trailing "null" elements
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    cout << "Original tree 1: ";
    printTree(root1);
    TreeNode* inverted1 = solution.invertTree(root1);
    cout << "Inverted tree 1: ";
    printTree(inverted1);

    // Example 2
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(1);
    cout << "Original tree 2: ";
    printTree(root2);
    TreeNode* inverted2 = solution.invertTree(root2);
    cout << "Inverted tree 2: ";
    printTree(inverted2);

    // Example 3
    TreeNode* root3 = nullptr;
    cout << "Original tree 3: ";
    printTree(root3);
    TreeNode* inverted3 = solution.invertTree(root3);
    cout << "Inverted tree 3: ";
    printTree(inverted3);

    return 0;
}
