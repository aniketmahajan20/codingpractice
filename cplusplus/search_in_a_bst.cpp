#include <iostream>

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
private:
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || val == root->val){   
            return root;
        }
        // Inorder traversal of the tree 
        // Only travel when thr returnNode value is NULL
        if ( val < root->val){
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }

    }
};

class SolutionInorder {
private:
    TreeNode* returnNode = NULL;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (val == root->val){
            this->returnNode = root;
        }
        // Inorder traversal of the tree 
        // Only travel when thr returnNode value is NULL
        if (returnNode == NULL && root->left != NULL){
            searchBST(root->left, val);
        }
        if (returnNode == NULL && root->right != NULL) {
            searchBST(root->right, val);
        }
        return returnNode;

    }
};