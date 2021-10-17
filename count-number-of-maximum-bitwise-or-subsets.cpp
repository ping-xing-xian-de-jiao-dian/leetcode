class Solution {
private:
    int len;

public:
    int cou = 0;
    void dfs(vector<int>& nums, int pos, int now, int target, int flag = 0){
        if (flag && now == target) ++cou;
        if (pos == len) return;
        dfs(nums, pos + 1, now | nums[pos], target, 1);
        dfs(nums, pos + 1, now, target);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        len = nums.size();
        for (int num : nums) maxi |= num;
        dfs(nums, 0, 0, maxi);
        return cou;
    }
};