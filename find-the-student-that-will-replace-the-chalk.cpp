class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        size_t len = chalk.size();
        if (len == 1) return 0;
        if (chalk[0] > k) return 0;
        for (int i = 1; i < len; ++i){
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k) return i;
            //k -= chalk[i];
        }
        k %= chalk[len - 1];
        for (int i = 0; i < len; ++i) if (chalk[i] > k) return i;
        return 0;
    }
};