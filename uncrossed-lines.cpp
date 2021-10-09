class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        size_t len1 = nums1.size(), len2 = nums2.size();
        int dp[len1 + 1][len2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len1; ++i){
            for (int j = 1; j <= len2; ++j){
                if (nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};