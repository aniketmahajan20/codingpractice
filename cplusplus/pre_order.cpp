#include <vector>
#include <stack>
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

class Solution_Recursion {
private:
    vector<int> result;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        pre_order(root);
        return result;
    }
    void pre_order(TreeNode* root){
        if (root == NULL){
            return;
        }
        result.push_back(root->val);
        pre_order(root->left);
        pre_order(root->right);
    }
};


class Solution_Iteration {
private:
    vector<int> result;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node;
        while(!s.empty()){
            node = s.top();
            result.push_back(node->val);
            s.pop();
            if (node->right != NULL){
                s.push(node->right);
            }
            if (node->left != NULL){
                s.push(node->left);
            }
        }
        return result;
    }
};