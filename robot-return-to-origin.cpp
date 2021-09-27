class Solution {
public:
    bool judgeCircle(string moves) {
        int d = 0, r = 0;
        for (char move : moves){
            if (move == 'U') --d;
            else if (move == 'D') ++d;
            else if (move == 'L') --r;
            else ++r;
        }
        return !d && !r;
    }
};