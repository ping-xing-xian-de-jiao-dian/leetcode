class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int pos1 = 0, pos2 = 0;
        size_t len1 = s.size(), len2 = t.size();
        char ss[205], tt[205];
        memset(ss, '\0', sizeof(ss));
        memset(tt, '\0', sizeof(tt));
        int s1 = -1, t1 = -1;
        while (pos1 < len1 || pos2 < len2){
            while (pos1 < len1 && s[pos1] == '#'){
                if (s1 > -1) --s1;
                ++pos1;
            }
            while (pos2 < len2 && t[pos2] == '#'){
                if (t1 > -1) --t1;
                ++pos2;
            }
            if (pos1 < len1) ss[++s1] = s[pos1++];
            if (pos2 < len2) tt[++t1] = t[pos2++];
        }
        if (s1 != t1) return 0;
        for (int i = 0; i <= s1; ++i){
            if (ss[i] != tt[i]) return 0;
            if (ss[i] == '\0') return 1;
        }
        return 1;
    }
};