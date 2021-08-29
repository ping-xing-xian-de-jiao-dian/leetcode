class Solution {
public:
    static bool cmp(string a, string b){
        if (a.length() != b.length()) return a.length() < b.length();
        for (int i = 0; i < a.length(); ++i){
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return 0;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        //for (string temp : nums) cout << temp <<' ';
        return nums[nums.size() - k];
    }
};