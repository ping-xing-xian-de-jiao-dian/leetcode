/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mini = INT_MAX;
    int pre;
    int flag = 0;
    void dfs(TreeNode* root){
        if (!root) return;
        dfs(root->left);
        if (!flag) pre = root->val, flag = 1;
        else mini = min(mini, root->val - pre), pre = root->val;
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return mini;
    }
};