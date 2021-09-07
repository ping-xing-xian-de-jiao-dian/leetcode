class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size_t len = nums.size();
        // dp[i]表示以第i个数为结尾的最长单增子序列长度
        int dp[len];
        int maxi = 1;
        for (int i = 0; i < len; ++i) dp[i] = 1;
        for (int i = 1; i < len; ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
                maxi = max(maxi, dp[i]);
            }
        }
        return maxi;
    }
};