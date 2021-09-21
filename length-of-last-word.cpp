class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.length() - 1;
        int cou = 0;
        while (s[pos] == ' ') --pos;
        while (pos >= 0 && s[pos] != ' ') ++cou, --pos;
        return cou;
    }
};