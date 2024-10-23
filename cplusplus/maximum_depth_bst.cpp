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

class Solution_Top_Down {
private:
    int answer;
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        this->max_depth(root, 1);
        return this->answer;
    }

    void max_depth(TreeNode* root, int depth){
        if (root == NULL){
            return;
        }
        this->answer = max(answer, depth);
        max_depth(root->left, depth+1);
        max_depth(root->right, depth+1);
    }
};

class Solution_Bottom_UP {
private:
    int answer;
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};