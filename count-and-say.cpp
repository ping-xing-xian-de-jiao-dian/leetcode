class Solution {
public:
    string count(string s){
        size_t len = s.size();
        int start = 0;
        string res = "";
        for (int i = 1; i <= len; ++i){
            if (i == len || s[i] != s[start]){
                res += to_string(i - start) + to_string(s[i - 1] - 48);
                start = i;
            }
        }
        return res;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";
        return count(countAndSay(n - 1));
    }
};