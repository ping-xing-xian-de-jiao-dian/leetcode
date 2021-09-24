class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        size_t len = nums.size();
        for (int i = 0; i < len; ++i) nums.emplace_back(nums[i]);
        vector<int> res(len, -1);
        stack<int> s;
        s.push(0);
        int pos = 1;
        while (!s.empty() && pos != 2 * len - 1){
            if (s.empty() || nums[pos] <= nums[s.top()]){
                if (pos < len) s.push(pos);
            } else {
                while (!s.empty() && nums[pos] > nums[s.top()]){
                    if (res[s.top()] == -1) res[s.top()] = nums[pos];
                    s.pop();
                }
                if (pos < len) s.push(pos);
            }
            ++pos;
        }
        return res;
    }
};