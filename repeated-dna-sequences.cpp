class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        vector<string> res;
        size_t len = s.size();
        if (len < 11) return res;

        int le = 0, ri = 9;
        while (le + 9 < len){
            string temp = s.substr(le, 10);
            if (++mp[temp] == 2) res.emplace_back(temp);
            ++le; ++ri;
        }
        return res;
    }
};