class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> le = nums, ri = nums;
        size_t len = nums.size();
        if (len == 1) return nums[0] == 0;

        for (int i = 1; i < len; ++i) le[i] += le[i - 1];
        for (int i = len - 2; i >= 0; --i) ri[i] += ri[i + 1];

        if (ri[1] == 0) return 0;
        for (int i = 1; i < len - 1; ++i){
            if (le[i - 1] == ri[i + 1]) return i;
        }
        if (le[len - 2] == 0) return len - 1;
        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int le = 0, ri = 0;
        size_t len = nums.size();
        for (int i = 1; i < len; ++i) ri += nums[i];
        for (int i = 0; i < len - 1; ++i){
            if (le == ri) return i;
            le += nums[i]; ri -= nums[i + 1];
        }
        if (le == 0) return len - 1;
        return -1;
    }
};