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

class Solution_Recursive {
public:
    bool isValidBST(TreeNode* root) {
        return is_valid_bst(root, NULL, NULL);
    }

    bool is_valid_bst(TreeNode* root, TreeNode* min, TreeNode* max){
        if (root == NULL){
            return true;
        }
        if (min != NULL && root->val <= min->val){
            return false;
        }
        if (max != NULL && root->val >= max->val){
            return false;
        }
        return is_valid_bst(root->left, min, root) && is_valid_bst(root->right, root, max);
    }
};
        
class Solution_Recursive_Inorder {
private:
    TreeNode* prev;
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        if (!isValidBST(root->left)){
            return false;
        };
        if (prev != NULL && root->val <= prev->val){
            return false;
        }
        prev = root;
        return isValidBST(root->right);
    }  
};