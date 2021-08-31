class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;

public:
    void dfs(int k, int n, int pos){
        if (k == 0 && n == 0){
            res.emplace_back(temp);
            return;
        }
        if (n < k || n > k * 9) return;
        if (pos > 9) return;
        temp.emplace_back(pos);
        dfs(k - 1, n - pos, pos + 1);
        temp.pop_back();
        dfs(k, n, pos + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
};