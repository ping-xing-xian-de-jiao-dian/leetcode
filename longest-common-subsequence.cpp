class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        const size_t len1 = text1.length(), len2 = text2.length();
        // dp[i][j]表示text1前i个数的子序列和text2前j个数的子序列最长公共长度
        // if (text1[i] != text2[j]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        // else dp[i][j] = dp[i - 1][j - 1] + 1;
        dp[0][0] = text1[0] == text2[0];
        for (int i = 1; i < len1; ++i) dp[i][0] = fmax(dp[i - 1][0], text1[i] == text2[0]);
        for (int i = 1; i < len2; ++i) dp[0][i] = fmax(dp[0][i - 1], text2[i] == text1[0]);
        for (int i = 1; i < len1; ++i){
            for (int j = 1; j < len2; ++j){
                if (text1[i] != text2[j]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};