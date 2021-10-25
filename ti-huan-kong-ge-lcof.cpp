class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (char t : s){
            if (t == ' ') res += "%20";
            else res += t;
        }
        return res;
    }
};