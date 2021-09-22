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
    vector<int> res;
    int maxiNum;
    int maxi = -1;
    int pre = INT_MAX;
    int cou = 0;
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        if (pre == INT_MAX || root->val == pre){
            pre = root->val;
            ++cou;
            if (cou > maxi){
                maxi = cou;
                maxiNum = root->val;
                res.resize(0);
                res.emplace_back(maxiNum);
            } else if (cou == maxi) {
                res.emplace_back(root->val);
            }
        } else {
            cou = 1;
            if (maxi == cou) res.emplace_back(root->val);
            pre = root->val;
        }
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};