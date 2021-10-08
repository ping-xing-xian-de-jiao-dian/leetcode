class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5) return 0;
        map<int, int> mp;
        for (auto bill : bills){
            if (bill == 5) mp[5]++;
            else if (bill == 10){
                if (mp[5]-- == 0) return 0;
                mp[10]++;
            } else {
                if (mp[10] != 0){
                    --mp[10];
                    if (mp[5]-- == 0) return 0;
                } else {
                    if (mp[5] < 3) return 0;
                    mp[5] -= 3;
                }
            }
        }
        return 1;
    }
};