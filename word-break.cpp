class Solution {
public:
    int inDic(string s, set<string>& wordSet){
        if (wordSet.find(s) != wordSet.end()) return 1;
        return 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        const size_t len = s.length();

        set<string> wordSet;
        for (string word : wordDict) wordSet.insert(word);

        if (len == 0) return 0;
        int *dp = new int[len];
        for (int i = 0; i < len; ++i) dp[i] = 0;

        // dp[i]表示从0-i能否用字典表示
        // dp[i]能表示的前提是dp[0]~dp[i - 1]中的dp[j]能表示(或者是第一个字符)，且dp[j + 1]~dp[i]在字典中
        dp[0] = inDic(s.substr(0, 1), wordSet);
        for (int i = 1; i < len; ++i){
            for (int j = 0; j < i; ++j){
                if (dp[j] && inDic(s.substr(j + 1, i - j), wordSet) || inDic(s.substr(0, i + 1), wordSet)){
                    dp[i] = 1; break;
                }
            }
        }
        return dp[len - 1];
    }
};