class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    size_t len;

public:
    int vis[105] = {0};
    void dfs(vector<int>& candidates, int pos, int target){
        if (!target){
            res.emplace_back(temp);
            return;
        }
        if (pos == len) return;

        if (target - candidates[pos] >= 0){
            // 如果和前者相同，要保证顺序
            if (pos > 0 && candidates[pos] == candidates[pos - 1] && !vis[pos - 1]){
                dfs(candidates, pos + 1, target);
            } else {
                temp.emplace_back(candidates[pos]);
                vis[pos] = 1;
                dfs(candidates, pos + 1, target - candidates[pos]);
                vis[pos] = 0;
                temp.pop_back();
            
                dfs(candidates, pos + 1, target);
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        len = candidates.size();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};