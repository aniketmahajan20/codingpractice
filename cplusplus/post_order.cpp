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
private:
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        this->post_order(root);
        return this->result;
    }
    void post_order(TreeNode* root){
        if (root == NULL){
            return;
        }
        post_order(root->left);
        post_order(root->right);
        this->result.push_back(root->val);
    }
};