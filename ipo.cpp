class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        size_t len = profits.size();
        int sum = w;
        // pro, cap优先队列
        int maxi = - 1;
        for (int profit : profits) maxi = max(maxi, profit);
        vector<priority_queue<int, vector<int>, greater<int>>> nums(maxi + 1, priority_queue<int, vector<int>, greater<int>>());
        // 初始化
        for (int i = 0; i < len; ++i){
            nums[profits[i]].push(capital[i]);
        }
        while (k){
            int i;
            // 枚举pro
            for (i = maxi; i >= 0; --i){
                if (!nums[i].empty() && nums[i].top() <= sum){
                    break;
                }
            }
            --k;
            if (i == - 1) break;
            sum += i;
            nums[i].pop();
        }
        return sum;
    }
};