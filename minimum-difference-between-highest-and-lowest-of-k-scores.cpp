class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        const size_t len = nums.size();
        if (len == 1) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = k - 1;
        int mini = nums[right] - nums[left];
        while (right < len){
            mini = min(mini, nums[right] - nums[left]);
            left++; right++;
        }
        return mini;
    }
};