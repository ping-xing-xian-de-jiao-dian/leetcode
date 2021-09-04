class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i]表示组成i块钱需要的最少硬币数
        // dp[i] = dp[i - coins[i]] + 1;
        const size_t len = coins.size();
        int dp[amount + 1];
        // 初始化
        memset(dp, 0x11111111, sizeof(dp));
        dp[0] = 0;
        // 遍历
        for (int j = 1; j <= amount; ++j){
            for (int i = 0; i < len; ++i){
                // 对于每个j，都会计算好几次，所以要和自己取小
                if (j - coins[i] >= 0)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] > amount ? - 1 : dp[amount];
    }
};