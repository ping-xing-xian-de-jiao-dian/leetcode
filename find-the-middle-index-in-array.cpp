class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        if (nums.size() == 0) return - 1;
        if (nums.size() == 1) return 0;
        for (int temp : nums) sum += temp;
        //if (sum == 0) return 0;
        int le = 0, ri = sum - nums[0];
        if (le == ri) return 0;
        for (int i = 0; i < nums.size() - 1; ++i){
            le += nums[i];
            ri -= nums[i + 1];
            if (le == ri) return i + 1;
        }
        return - 1;
    }
};