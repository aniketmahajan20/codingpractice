#include <vector>
#include <stack>
using namespace std;
//Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        inorder(root);
        return result;
    }
    void inorder(TreeNode* root){
        if (root == NULL){
            return;
        }
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
};

class Solution_Iteration {
private:
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(!s.empty() || node != NULL){
            while(node != NULL){
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            result.push_back(node->val);
            node = node->right;
        }
        return result;
    }
};