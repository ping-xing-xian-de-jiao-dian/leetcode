class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> cou(10001);
        for (int num : nums) cou[abs(num)]++;
        vector<int> res;
        for (int i = 0; i < 10001; ++i){
            for (int j = 0; j < cou[i]; ++j){
                res.emplace_back(i * i);
            }
        }
        return res;
    }
};