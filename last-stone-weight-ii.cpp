class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 石头可以分为加上的和减去的
        // 设减去的为neg，那么加上的就是sum - neg，最后剩下的就是sum - neg - neg
        // 我们的目标是让剩下的最小，那么就是让neg在不大于sum / 2的情况下最大
        // 设dp[i + 1][j]表示前i块石头能构成的neg == j的情况
        int sum = 0;
        for (int a : stones) sum += a;
        int half = sum / 2;
        size_t len = stones.size();
        int dp[len + 1][half + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        int target = -1;
        for (int i = 1; i <= len; ++i){
            for (int j = 0; j <= half; ++j){
                if (j - stones[i - 1] >= 0){
                    dp[i][j] = dp[i - 1][j - stones[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                if (dp[i][j]) target = max(target, j);
            }
        }
        return sum - target - target;
    }
};