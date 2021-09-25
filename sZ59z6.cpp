/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* root, int res[]){
        if (!root) return;
        res[root->val] = 1;
        dfs(root->left, res);
        dfs(root->right, res);
    }
    
    int numColor(TreeNode* root) {      
        int res[1001] = {0};
        dfs(root, res);
        int cou = 0;
        
        for (int a : res) cou += a;
        return cou;
    }
};