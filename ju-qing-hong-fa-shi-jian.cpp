class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        size_t len = requirements.size(), len2 = increase.size();
        vector<int> C(len2 + 1, 0), R(len2 + 1, 0), H(len2 + 1, 0);
        for (int i = 1; i <= len2; ++i){
            C[i] = C[i - 1] + increase[i - 1][0];
            R[i] = R[i - 1] + increase[i - 1][1];
            H[i] = H[i - 1] + increase[i - 1][2];
        }
        vector<int> res;
        for (int i = 0; i < len; ++i){
            int a = lower_bound(C.begin(), C.end(), requirements[i][0]) - C.begin();
            int b = lower_bound(R.begin(), R.end(), requirements[i][1]) - R.begin();
            int c = lower_bound(H.begin(), H.end(), requirements[i][2]) - H.begin();
            if (a == len2 + 1 || b == len2 + 1 || c == len2 + 1) res.emplace_back(-1);
            else res.emplace_back(max(a, max(b, c)));
        }
        return res;
    }
};