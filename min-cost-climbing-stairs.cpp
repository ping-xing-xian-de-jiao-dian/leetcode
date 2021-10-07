class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t len = cost.size();
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < len; ++i){
            dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
        }
        return min(dp[len - 1], dp[len - 2]);
    }
};