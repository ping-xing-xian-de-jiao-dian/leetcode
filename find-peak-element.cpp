class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        size_t len = nums.size();
        if (len == 1 || nums[0] > nums[1]) return 0;
        if (nums[len - 1] > nums[len - 2]) return len - 1;
        int le = 1, ri = len - 2;
        while (le <= ri){
            int mid = (ri - le) / 2 + le;
            if (nums[mid + 1] > nums[mid]) le = mid + 1;
            else ri = mid - 1;
        }
        return le;
    }
};