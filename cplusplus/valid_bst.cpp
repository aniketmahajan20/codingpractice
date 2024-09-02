#include <iostream>
#include <vector>
#include <queue>

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

class SolutionRecursiveValidRange {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }

    bool isValid(TreeNode* root, TreeNode* low, TreeNode* high) {
        if (root == NULL) {
            return true;
        }

        if ((low != NULL && root->val <= low->val) || (high != NULL && root->val >= high->val)){
            return false;
        }
        return isValid(root->left, low, root) && isValid(root->right, root, high);
    }
};

class SolutionRecursiveInorder {
private:
    TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (!isValidBST(root->left)){
            return false;
        }
        if (prev != NULL && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return isValidBST(root->right);
    }
};