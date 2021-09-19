class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int len = nums.size();
        int cou = 0;
        vector<int> ma(len, nums[0]);
        vector<int> mi(len, nums[len - 1]);
        for (int i = 1; i < len - 1; ++i) ma[i] = max(ma[i - 1], nums[i]),cout <<ma[i];
        for (int i = len - 2; i > 0; --i) mi[i] = min(mi[i + 1], nums[i]);
        
        for (int i = 1; i < len - 1; ++i){
            if (!(nums[i] <= ma[i - 1] || nums[i] >= mi[i + 1])){
                cou += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ++cou;
            }
        }
        return cou;
    }
};