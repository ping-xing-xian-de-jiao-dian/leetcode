class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        size_t len = nums.size();
        // dp[i]表示组成i的组合个数
        unsigned long long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= target; ++i){
            for (int j = 0; j < len; ++j){
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};