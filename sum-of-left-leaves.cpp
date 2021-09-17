class Solution {
public:
    int sum = 0;
    void Traverse(TreeNode* root){
        if (!root) return;
        if (root->left && !root->left->left && !root->left->right) sum += root->left->val;
        Traverse(root->left);
        Traverse(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        Traverse(root);
        return sum;
    }
};