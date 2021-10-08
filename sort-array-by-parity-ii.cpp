class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1, even = 0;
        size_t len = nums.size();
        vector<int> res(len);
        for (int num : nums){
            if (num & 1) res[odd] = num, odd += 2;
            else res[even] = num, even += 2;
        }
        return res;
    }
};