class Solution {
public:
    const int mod = 1000'000'007;
    int fib(int n) {
        int nums[3] = {0, 1};
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        while (--n){
            nums[2] = (nums[0] + nums[1]) % mod;
            nums[0] = nums[1];
            nums[1] = nums[2];
        }
        return nums[2];
    }
};