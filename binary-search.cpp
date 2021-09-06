class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t len = nums.size();
        int left = 0, right = len - 1;
        while (left <= right){
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return - 1;
     }
};