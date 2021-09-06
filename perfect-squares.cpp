class Solution {
public:
    int numSquares(int n) {
        int pows[101];
        for (int i = 1; i * i <= n; ++i) pows[i] = i * i;
        // dp[j]表示和为i的完全平方数个数最小值
        // dp[j] = min(dp[j] - pows[i]] + 1, dp[j]) if dp[j - pows[i]] != INT_MAX
        int dp[n + 1];
        memset(dp, 0x11111111, sizeof(dp));
        dp[0] = 0;
        // 遍历平方数
        for (int i = 1; i * i <= n; ++i){
            // 遍历回溯
            for (int j = 1; j < n + 1; ++j){
                if (j >= pows[i] && dp[j - pows[i]] <= n){
                    dp[j] = min(dp[j - pows[i]] + 1, dp[j]);
                } else {
                    dp[j] = min(dp[j], dp[j - 1] + 1);
                }
            }
        }
        return dp[n];
    }
};