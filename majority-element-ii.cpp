class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        size_t len = nums.size();
        int t = len / 3;
        vector<int> res;
        unordered_map<int, int> mp;
        for (int num : nums) ++mp[num];
        for (auto& [k, v] : mp){
            if (v > t) res.emplace_back(k);
        }
        return res;
    }
};