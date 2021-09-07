class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[i][0]买入第一笔
        // dp[i][1]卖出第一笔
        //    ....
        // dp[i][2 * k - 2]买入第k笔
        // dp[i][2 * k - 1]卖出第k笔
        // 前i个位置每个状态能取得的最大利润
        size_t len = prices.size();
        if (len <= 1 || k == 0) return 0;
        int dp[len][2 * k];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 2 * k; i += 2) dp[0][i] = - prices[0];
        for (int i = 1; i < len; ++i){
            for (int j = 0; j < 2 * k; ++j){
                // 第一笔买入的情况
                if (j == 0){
                    dp[i][j] = max(dp[i - 1][j], - prices[i]);
                    continue;
                }
                // 大小比较，1.前一个没进行操作。2.如果是买入，前一个卖出-该价格；如果是卖出，前一个买入+该价格
                int flag = j & 1 ? 1 : - 1;
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + flag * prices[i]);
            }
        }
        return *max_element(dp[len - 1], dp[len - 1] + 2 * k);
    }
};