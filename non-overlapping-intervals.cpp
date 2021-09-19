class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 同起点取最小
        sort(intervals.begin(), intervals.end());
        size_t len = intervals.size();
        int cou = 0;
        int ri = intervals[0][1];
        for (int i = 1; i < len; ++i){
            int start = intervals[i][0], end = intervals[i][1];
            if (start == intervals[i - 1][0]){
                ++cou; continue;
            }
            if (start >= ri){
                ri = end; continue;
            } else {
                ri = min(end, ri);
                ++cou;
            }
        }
        return cou;
    }
};