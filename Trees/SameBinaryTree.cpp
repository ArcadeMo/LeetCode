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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: If both nodes are nullptr, they are equivalent (both trees are empty at this position)
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Base case 2: If one of the nodes is nullptr and the other is not, they are not equivalent
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Base case 3: If the values of the nodes are different, the trees are not equivalent
        if (p->val != q->val) {
            return false;
        }

        // Recursive case: Check if the left subtrees are equivalent and the right subtrees are equivalent
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to print the result
void printIsSameTree(Solution& solution, TreeNode* p, TreeNode* q) {
    bool isSame = solution.isSameTree(p, q);
    cout << "The trees are " << (isSame ? "equivalent" : "not equivalent") << endl;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);
    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);
    cout << "Tree 1: ";
    printIsSameTree(solution, p1, q1);

    // Example 2
    TreeNode* p2 = new TreeNode(4);
    p2->left = new TreeNode(7);
    TreeNode* q2 = new TreeNode(4);
    q2->right = new TreeNode(7);
    cout << "Tree 2: ";
    printIsSameTree(solution, p2, q2);

    // Example 3
    TreeNode* p3 = new TreeNode(1);
    p3->left = new TreeNode(2);
    p3->right = new TreeNode(3);
    TreeNode* q3 = new TreeNode(1);
    q3->left = new TreeNode(3);
    q3->right = new TreeNode(2);
    cout << "Tree 3: ";
    printIsSameTree(solution, p3, q3);

    return 0;
}
