class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, maxi = 0;
        for (int num : nums) sum += num, maxi = max(maxi, num);
        if (sum & 1) return 0;
        if (maxi * 2 > sum) return 0;
        const int target = sum / 2;
        const size_t len = nums.size();
        // dp[i][j]表示在前i个数中是否存在一种选取方案使得被选取的正整数的和等于j
        // dp[i][j] = 如果dp[i - 1][j]能分，那肯定能分；或者dp[i - 1][j - nums[i]]能分，就能分
        int dp[len][target + 1];
        memset(dp, 0, sizeof(dp));
        // 初始条件
        for (int i = 0; i < len; ++i) dp[i][0] = 1, dp[i][nums[i]] = 1;
        // 开始遍历
        for (int i = 1; i < len; ++i){
            for (int j = 0; j < target + 1; ++j){
                if (dp[i - 1][j] == 1 || j >= nums[i] && dp[i - 1][j - nums[i]] == 1) dp[i][j] = 1;
            }
        }
        return dp[len - 1][target];
    }
};