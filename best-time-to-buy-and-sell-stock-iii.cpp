class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t len = prices.size();
        if (len <= 1) return 0;
        // 0 没有买过股票
        // 1 买了第一张股票，还没卖
        // 2 买了第一张且卖掉了
        // 3 买了第二张股票，还没卖
        // 4 买了第二张且卖掉了
        // dp[i]表示在这种情况下能拥有的最大金额

        /*
        int dp[len][5];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = dp[0][3] = - prices[0];
        for (int i = 1; i < len; ++i){
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return max(dp[len - 1][4], dp[len - 1][2]);
        */

        // 内存可以优化，因为只用到了4个变量
        int buy1 = - prices[0], buy2 = - prices[0], sell1 = 0, sell2 = 0;
        for (int i = 0; i < len; ++i){
            int temp = sell1;
            sell1 = max(sell1, buy1 + prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
            buy1 = max(buy1, - prices[i]);
            buy2 = max(buy2, temp - prices[i]);
        }
        return max(sell1, sell2);
    }
};