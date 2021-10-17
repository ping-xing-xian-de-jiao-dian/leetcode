class Solution {
public:
    int ka, res;
    void dfs(TreeNode* root){
        if (!root) return;
        dfs(root->left);
        if (--ka == 0){
            res = root->val;
            return;
        }
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        ka = k;
        dfs(root);
        return res;
    }
};