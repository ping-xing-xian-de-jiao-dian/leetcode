class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        int count = 0;
        size_t len = nums.size();
        if (len == 1) return;
        while (len - count != slow){
            if (nums[fast] != 0 && fast != slow){
                nums[slow++] = nums[fast++];
            }
            while (fast < len && nums[fast] == 0){
                ++fast;
                ++count;
            }
            if (fast == len) break;
            nums[slow++] = nums[fast++];
        }
        while (slow < len) nums[slow] = 0, ++slow;
    }
};