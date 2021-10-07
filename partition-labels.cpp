class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> le_ri(26, vector<int>(2, -1));
        size_t len = s.size();
        for (int i = 0; i < len; ++i){
            int temp = s[i] - 97;
            if (le_ri[temp][0] == -1){
                le_ri[temp][0] = le_ri[temp][1] = i;
            } else {
                le_ri[temp][1] = i;
            }
        }
        sort(le_ri.begin(), le_ri.end());
        vector<int> res;
        int end = le_ri[0][1];

        for (auto lr : le_ri){
            if (lr[0] == -1) continue;
            if (lr[0] > end && end != -1){
                res.emplace_back(end + 1);
                end = lr[1];
            } else {
                end = max(end, lr[1]);
            }
        }
        res.emplace_back(end + 1);
        for (int i = res.size() - 1; i >= 1; --i) res[i] -= res[i - 1];
        return res;
    }
};