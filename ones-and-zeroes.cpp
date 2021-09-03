class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        const size_t len = strs.size();
        // dp[i][j][k]表示前i个数包含j个0和k个1的最大子集大小
        // dp[i][j][k] = max(dp[i - 1][j - 0的个数][k - 1的个数] + 1, dp[i - 1][j][k])
        const int mm = m + 1, nn = n + 1;
        int dp[len + 1][mm][nn];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < len + 1; ++i){
            for (int j = 0; j < mm; ++j){
                for (int k = 0; k < nn; ++k){
                    int count[2] = {0};
                    for (char temp : strs[i - 1]) count[temp - 48]++;
                    if (j >= count[0] && k >= count[1])
                        dp[i][j][k] = max(dp[i - 1][j - count[0]][k - count[1]] + 1, dp[i - 1][j][k]);
                    else 
                        dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
        return dp[len][m][n];
    }
};