class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t len1 = word1.length(), len2 = word2.length();
        int mini = min(len1, len2);
        int dp[len1 + 1][len2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len1; ++i){
            for (int j = 1; j <= len2; ++j){
                if (word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return len1 + len2 - (dp[len1][len2] << 1);
    }
};