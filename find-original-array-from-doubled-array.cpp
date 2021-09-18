class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int len = changed.size();
        vector<int> res;
        if (len & 1) return res;
        sort(changed.begin(), changed.end());
        vector<int> count(200001, 0);
        for (int a: changed) count[a]++;
        
        for (int a : changed){
            if (!count[a]) continue;
            if (count[a << 1] <= 0 || len < 0){
                vector<int> temp; return temp;
            }
            count[a << 1]--; count[a]--; len -= 2;
            res.emplace_back(a);
        }
        return res;
    }
};