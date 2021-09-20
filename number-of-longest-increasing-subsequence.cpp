class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        size_t len = nums.size();
        // 最长长度、个数
        vector<vector<int>> dp(len, vector<int>(2, 1));
        int cou = 0, maxi = 0;
        for(int i = 0; i < len; ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] > nums[j]){
                    if (dp[j][0] + 1 > dp[i][0]) dp[i][0] = dp[j][0] + 1, dp[i][1] = dp[j][1];
                    else if (dp[j][0] + 1 == dp[i][0]) dp[i][1] += dp[j][1];
                }
            }
            if (dp[i][0] > maxi) maxi = dp[i][0], cou = dp[i][1];
            else if (dp[i][0] == maxi) cou += dp[i][1];
        }
        return cou;
    }
};