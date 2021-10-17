class Solution {
public:
    bool areNumbersAscending(string s) {
        int temp = 0;
        int pre = -1;
        int len = s.size();
        for (int i = 0; i < len; ++i){
            if (s[i] >= '0' && s[i] <= '9'){
                while (i < len && s[i] >= '0' && s[i] <= '9'){
                    temp = temp * 10 + s[i] - 48;
                    ++i;
                }
                if (temp > pre){
                    pre = temp; temp = 0;
                } else {
                    return 0;
                }
            }
        }
        return 1;
    }
};