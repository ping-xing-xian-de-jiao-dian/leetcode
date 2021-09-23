class Solution {
public:
    int minimumOperations(string leaves) {
        size_t len = leaves.length();
        vector<vector<int>> dp(len, vector<int>(3, len + 1));
        dp[0][0] = leaves[0] == 'r' ? 0 : 1;
        for (int i = 1; i < len; ++i){
            if (leaves[i] == 'r'){
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            } else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][2] = min(dp[i - 1][1] + 1, dp[i - 1][2] + 1);
            }
        }
        return min(min(dp[len - 1][2], dp[len - 2][1] + (leaves[len - 1] == 'y')), 
        dp[len - 3][0] + (leaves[len - 2] == 'r') + (leaves[len - 1] == 'y'));
    }
};