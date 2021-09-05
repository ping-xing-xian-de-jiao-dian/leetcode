class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i){
            for (int  j = 0; j < n; ++j){
                if (land[i][j] && (i == 0 || i > 0 && land[i - 1][j] == 0) && (j == 0 || j > 0 && land[i][j - 1] == 0)){
                    vector<int> temp = {i, j};
                    res.emplace_back(temp);
                }
            }
        }
        for (int k = 0; k < res.size(); ++k){
            for (int i = res[k][0]; i < m; ++i){
                if (i == m - 1 || land[i + 1][res[k][1]] == 0){
                    res[k].emplace_back(i);
                    break;
                }
            }
            for (int j = res[k][1]; j < n; ++j){
                if (j == n - 1 || land[res[k][0]][j + 1] == 0){
                    res[k].emplace_back(j);
                    break;
                }
            }
        }
        return res;
    }
};