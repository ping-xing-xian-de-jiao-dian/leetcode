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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int cou = 0, res;
        while (!que.empty()){
            int len = que.size();
            for (int i = 0; i < len; ++i){
                TreeNode* pre = que.front();
                que.pop();
                if (i == 0) res = pre->val;
                if (pre->left) que.push(pre->left);
                if (pre->right) que.push(pre->right);
            }
        }
        return res;
    }
};