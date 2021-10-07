class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        size_t len1 = nums1.size(), len2 = nums2.size();
        int dp[len1 + 1][len2 + 1];
        // dp[i][j]表示nums1以i结尾和nums2以j结尾最长公共长度
        memset(dp, 0, sizeof(dp));
        int maxi = -1;
        for (int i = 1; i <= len1; ++i){
            for (int j = 1; j <= len2; ++j){
                if (nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};