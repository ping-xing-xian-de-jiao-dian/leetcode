class Solution {
public:
    int oddLen(int a){
        if (a & 1){
            return (a + 1) / 2;
        }
        return (a + 1) / 2 + 1;
    }

    int sumOddLengthSubarrays(vector<int>& arr) {
        const size_t len = arr.size();
        int a, b, c;
        a = arr[0];
        int sum = arr[0];
        // dp[i]表示以第i个数为末尾的奇数长度子数组和
        // dp[i] = dp[i - 2] + dp[i - 2].size() * (arr[i - 1] + arr[i]) + arr[i];
        for (int i = 1; i < len; ++i){
            if (i == 1){
                b = arr[i], sum += b;
                continue;
            }
            else c = a + oddLen(i - 2) * (arr[i - 1] + arr[i]) + arr[i], sum += c;
            a = b; b = c;
        } return sum;
    }
};