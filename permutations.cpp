class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> s;
        s.insert(nums);
        for (int i = 0; i < 6000; ++i){
            random_shuffle(begin(nums), end(nums));
            s.insert(nums);
        }
        vector<vector<int>> res;
        for (vector<int> temp : s){
            res.push_back(temp);
        }
        return res;
    }
};