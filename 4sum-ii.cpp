class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        size_t len = nums1.size();
        int cou = 0;
        for (int n1 : nums1) for (int n2 : nums2) mp[n1 + n2]++;
        for (int n3 : nums3){
            for (int n4 : nums4){
                cou += mp[- n3 - n4];
            }
        }
        return cou;
    }
};