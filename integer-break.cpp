class Solution {
public:
    // 把n尽可能分为i个大小相同的数时的乘积
    int cal(int i, int n){
        int num = n / i;
        int r = n % i;
        int sum = 1;
        for (int j = 0; j < i; ++j){
            if (r) sum *= num + 1, --r;
            else sum *= num;
        }
        return sum;
    }

    int integerBreak(int n) {
        int maxi = n - 1;
        for (int i = 2; i <= n / 2; ++i){
            maxi = max(maxi, cal(i, n));
        }
        return maxi;
    }
};