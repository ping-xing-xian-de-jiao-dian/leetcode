class Solution {
private:
    int cou;
    size_t len;

public:
    void dfs(vector<int>& nums, int pos, int target){
        if (pos == len && !target){
            ++cou;
            return;
        } else if (pos == len) return;
        dfs(nums, pos + 1, target - nums[pos]);
        dfs(nums, pos + 1, target + nums[pos]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        cou = 0;
        len = nums.size();
        dfs(nums, 0, target);
        return cou;
    }
};