// 方法1
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         const size_t len = nums.size();
//         if (len == 1) return;
//         vector<int> newNums(len);
//         for (int i = 0; i < len; ++i){
//             newNums[(i + k) % len] = nums[i];
//         }
//         nums = newNums;
//     }
// };
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
