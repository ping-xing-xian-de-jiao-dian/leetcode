class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        size_t len = prices.size();
        // dp[i][0]表示买了i股票，dp[i][1]表示卖了i股票
        int dp[len][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = - prices[0];
        for (int i = 1; i < len; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1]);
        }
        return dp[len - 1][1];
    }
};