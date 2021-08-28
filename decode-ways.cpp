class Solution {
public:
    int numDecodings(string s) {
        // dp[i]表示从0到i有多少种解码方式
        // dp[i] = dp[i -  1] + （两位数如果能解码的话）
        if (s[0] == '0') return 0;
        int dp[101];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        const size_t len = s.length();
        for (int i = 1; i < len; ++i){
            if (s[i] == '0'){
                if (s[i - 1] != '1' && s[i - 1] != '2') return 0;
                else {
                    if (i == 1) dp[i] = 1;
                    else dp[i] = dp[i - 2];
                }
            } else {
                int temp = (s[i - 1] - 48) * 10 + s[i] - 48;
                if (temp > 0 && temp < 27){
                    if (s[i - 1] == '0') dp[i] = dp[i - 1];
                    else {
                        if (i == 1) dp[i] = dp[i - 1] + 1;
                        else dp[i] = dp[i - 2] + dp[i - 1];
                    }
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[len - 1];
    }
};