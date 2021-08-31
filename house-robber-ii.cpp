class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101];
        const size_t len = nums.size();
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        memset(dp, 0, sizeof(dp));
        // 打劫0，最后一位不用看了
        dp[0] = dp[1] = nums[0];
        for (int i = 2; i < len - 1; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int maxi = dp[len - 2];
        // 不打劫0
        for (int i = 0; i < len; ++i) dp[i] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < len; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return max(maxi, dp[len - 1]);
    }
};