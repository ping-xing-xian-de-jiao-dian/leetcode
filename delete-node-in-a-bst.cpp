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
    TreeNode* predecessor(TreeNode* root){
        root = root->left;
        while (root->right) root = root->right;
        return root;
    }

    TreeNode* successor(TreeNode* root){
        root = root->right;
        while (root->left) root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (key < root->val) deleteNode(root->left, key);
        else if (key > root->val) deleteNode(root->right, key);

        if (root->val == key){
            // 1.叶子节点 2.无右节点 3.有右节点
            if (!root->left && !root->right){
                root = nullptr;
            } else if (!root->right) {
                TreeNode* select = predecessor(root);
                root->val = select->val;
                deleteNode(root, select->val);
            } else {
                TreeNode* select = successor(root);
                root->val = select->val;
                deleteNode(root, select->val);
            }
        }

        return root;
    }
};