#define MOD 1000000007
class Solution {
public:
    int numDecodings(string s) {
        size_t len = s.size();
        long long dp[len + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if (s[0] == '0') return 0;

        if (s[0] == '*') dp[1] = 9;
        else dp[1] = 1;
        if (len == 1) return dp[1];

        for (int i = 2; i <= len; ++i){
            if (s[i - 1] == '*'){
                if (s[i - 2] == '*') dp[i] = dp[i - 1] * 9 % MOD + dp[i - 2] * 15 % MOD;
                else if (s[i - 2] == '1') dp[i] = dp[i - 1] * 9 % MOD + dp[i - 2] * 9 % MOD;
                else if (s[i - 2] == '2') dp[i] = dp[i - 1] * 9 % MOD + dp[i - 2] * 6 % MOD;
                else dp[i] = dp[i - 1] * 9 % MOD;
            } else if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2] == '2') dp[i] = dp[i - 2];
                else if (s[i - 2] == '*') dp[i] = dp[i - 2] * 2 % MOD;
                else return 0;
            } else if (s[i - 1] >= '1' && s[i - 1] <= '6') {
                if (s[i - 2] == '1' || s[i - 2] == '2') dp[i] = dp[i - 1] + dp[i - 2];
                else if (s[i - 2] == '*') dp[i] = dp[i - 1] + dp[i - 2] * 2 % MOD;
                else dp[i] = dp[i - 1];
            } else {
                if (s[i - 2] == '1' || s[i - 2] == '*') dp[i] = dp[i - 1] + dp[i - 2];
                else dp[i] = dp[i - 1];
            }
            dp[i] %= MOD;
        }
        return dp[len];
    }
};