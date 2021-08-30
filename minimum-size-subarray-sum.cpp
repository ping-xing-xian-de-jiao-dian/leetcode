class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = nums[0];
        int mini = INT_MAX, flag = 0;
        const size_t len = nums.size();
        while (right < len){
            while (right < len && sum < target){
                ++right;
                if (right == len) return mini == INT_MAX ? 0 : mini;
                sum += nums[right];
            }
            flag = 0;
            while (left <= right && sum >= target){
                sum -= nums[left];
                ++left;
                flag = 1;
            }
            if (flag) mini = min(mini, right - left + 2);
        }
        return mini == INT_MAX ? 0 : mini;
    }
};