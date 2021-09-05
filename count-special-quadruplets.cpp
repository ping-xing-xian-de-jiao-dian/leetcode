class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        for (int i = 0; i < len - 3; ++i){
            for (int j = i + 1; j < len - 2; ++j){
                for (int k = j + 1; k < len - 1; ++k){
                    for (int q = k + 1; q < len; ++q){
                        if (nums[i] + nums[j] + nums[k] == nums[q]){
                            ++count;
                        }
                    }
                }
            }
        }
        return count;
    }
};