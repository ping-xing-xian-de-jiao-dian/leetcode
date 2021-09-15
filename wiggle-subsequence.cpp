class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        size_t len = nums.size();
        // dp[i]以第i个数结尾最长摆动序列长度
        int dp[len][2];
        int maxi = 1;
        for (int i = 0; i < len; ++i) dp[i][0] = dp[i][1] = 1;
        for (int i = 1; i < len; ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] > nums[j]) dp[i][0] = max(dp[j][1] + 1, dp[i][0]);
                else if (nums[i] < nums[j]) dp[i][1] = max(dp[j][0] + 1, dp[i][1]);
                maxi = max(maxi, max(dp[i][0], dp[i][1]));
            }
        }
        return maxi;
    }
};