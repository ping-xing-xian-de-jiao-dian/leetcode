class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int len = nums.size();
        int count = 0;
        for (int i = 0; i < len; ++i){
            for (int j = i; j < len; ++j){
                if (nums[i] - nums[j] == k || nums[i] - nums[j] == -k) ++count;
            }
        }
        return count;
    }
};