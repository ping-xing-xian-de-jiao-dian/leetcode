class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos1 = 0, pos2 = 0;
        size_t len1 = s.length(), len2 = t.length();
        if (len1 > len2) return 0;
        while (pos2 <= len2){
            if (len1 == pos1) return 1;
            if (s[pos1] == t[pos2]) ++pos1, ++pos2;
            else ++pos2;
        }
        return 0;
    }
};