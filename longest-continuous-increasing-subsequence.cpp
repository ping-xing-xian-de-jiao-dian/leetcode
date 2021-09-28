class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        size_t len = nums.size();
        int res = 1;
        int maxi = 1;
        for (int i = 1; i < len; ++i){
            if (nums[i] > nums[i - 1]){
                ++res;
                maxi = max(maxi, res);
            } else {
                res = 1;
            }
        }
        return maxi;
    }
};