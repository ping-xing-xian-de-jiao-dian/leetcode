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
    TreeNode* find(vector<int>& nums, int low, int high){
        if (low > high) return nullptr;
        int maxi = nums[low], pos = low;
        for (int i = low; i <= high; ++i) if (nums[i] > maxi) maxi = nums[i], pos = i;
        TreeNode* root = new TreeNode(nums[pos]);
        root->left = find(nums, low, pos - 1);
        root->right = find(nums, pos + 1, high);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return find(nums, 0, nums.size() - 1);
    }
};