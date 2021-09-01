class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        int mini = min(p->val, q->val), maxi = max(p->val, q->val);
        while (1){
            if (root->val < mini) root = root->right;
            else if (root->val > maxi) root = root->left;
            else return root;
        }
    }
};