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

class Solution_Recursive {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        level_order(root, 0);
        return result;
    }
    void level_order(TreeNode* root, int level){
        if (result.size() == level){
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        if (root->left != NULL){
            level_order(root->left, level +1);
        }
        if (root->right != NULL){
            level_order(root->right, level +1);
        }
    }
};

class Solution_Iterative {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        while(!q.empty()){
            level.clear();
            int queue_size = q.size();
            for (int i = 0; i < queue_size; i++){
                curr = q.front();
                level.push_back(curr->val);
                q.pop();
                if (curr->left != NULL){
                    q.push(curr->left);
                }
                if (curr->right != NULL){
                    q.push(curr->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};