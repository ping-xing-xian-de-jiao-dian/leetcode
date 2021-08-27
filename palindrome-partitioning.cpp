class Solution {
private:
    int dp[17][17];
    vector<vector<string>> res;
    vector<string> temp;
    size_t len;

public:
    int isPalindrome(string a){
        int len = a.size();
        for (int i = 0; 2 * i < len; ++i){
            if (a[i] != a[len - i - 1]) return 0;
        } return 1;
    }

    void Combine(string s, int pos){
        if (pos == len){
            res.emplace_back(temp);
            return;
        }
        for (int i = pos; i < len; ++i){
            if (dp[pos][i]){
                temp.emplace_back(s.substr(pos, i - pos + 1));
                Combine(s, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        len = s.length();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 17; ++i) dp[i][i] = 1;
        int left = 0, right = len - 1;
        for (left = 0; left < len; ++left){
            for (right = len - 1; right > left; --right){
                if (dp[left][right] == 1) continue;
                if (isPalindrome(s.substr(left, right - left + 1))){
                    int le = left, ri = right;
                    while (le <= ri) dp[le++][ri--] = 1;
                }
            }
        }
        Combine(s, 0);
        return res;
    }
};