class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t len = prices.size();
        if (len == 0) return 0;
        // 我们目前持有一支股票，对应的「累计最大收益」记为 f[i][0];
        // 我们目前不持有任何股票，并且处于冷冻期中，对应的「累计最大收益」记为 f[i][1];
        // 我们目前不持有任何股票，并且不处于冷冻期中，对应的「累计最大收益」记为 f[i][2];
        int dp[len][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = - prices[0];
        for (int i = 1; i < len; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[len - 1][1], dp[len - 1][2]);
    }
};