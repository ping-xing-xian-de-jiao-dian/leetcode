class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 从右往左，如果不满足，-1，后面全变成9，如果不满足且是0，再往前
        vector<int> nums;
        while (n){
            nums.emplace_back(n % 10);
            n /= 10;
        }
        size_t len = nums.size();
        int flag = -1;
        for (int i = 1; i < len; ++i){
            if (nums[i] > nums[i - 1]){
                if (nums[i] != 0){
                    --nums[i];
                }
                flag = i;
            }
        }
        for (int i = 0; i < flag; ++i) nums[i] = 9;
        int res = 0;
        for (int i = len - 1; i >= 0; --i) res = res * 10 + nums[i];
        return res;
    }
};