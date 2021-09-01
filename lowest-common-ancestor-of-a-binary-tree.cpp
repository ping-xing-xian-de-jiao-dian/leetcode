class Solution {
public:
    int flag = 0;
    TreeNode* res = nullptr;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if (flag) return 1;
        if (!root) return 0;
        int le = dfs(root->left, p, q);
        int ri = dfs(root->right, p, q);
        if (((root->val == p->val || root->val == q->val) && (le || ri)) || (le && ri)){
            if (!flag) 
                res = root;
            flag = 1;
            return 1;
        }
        // 中间为什么是或而不是与，因为两个条件只要满足一个就可以继续计算下去了！！
        return ((root->val == p->val || root->val == q->val) || (le || ri)) || (le && ri);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};