class Solution {
public:
    int centerCount(string s, int i, int j){
        size_t len = s.size();
        int cou = 0;
        for (int dis = 0; dis < len; ++dis){
            if (i - dis >= 0 && j + dis < len){
                if (s[i - dis] == s[j + dis]) ++cou;
                else return cou;
            }
        }
        return cou;
    }

    int countSubstrings(string s) {
        size_t len = s.size();
        int cou = 0;
        // 奇数长度中心枚举
        for (int i = 0; i < len; ++i) cou += centerCount(s, i, i);
        // 偶数长度中心枚举
        for (int i = 0; i < len - 1; ++i) if (s[i] == s[i + 1]) cou += centerCount(s, i, i + 1);
        return cou;
    }
};