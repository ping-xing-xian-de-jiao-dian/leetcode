class Solution {
public:
    // 以root为根，所有的路径
    int sum(TreeNode* root, int targetSum){
        if (!root) return 0;
        return sum(root->left, targetSum - root->val) + sum(root->right, targetSum - root->val) + (targetSum == root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return sum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};