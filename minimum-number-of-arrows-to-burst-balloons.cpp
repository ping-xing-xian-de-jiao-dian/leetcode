class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int le, ri;
        size_t len = points.size();
        int cou = 0, flag = 0;
        for (const auto& p : points){
            if (!flag){
                flag = 1;
                le = p[0]; ri = p[1];
                ++cou;
                continue;
            }
            if (p[0] > ri){
                le = p[0];
                ri = p[1];
                ++cou;
            } else {
                ri = min(ri, p[1]);
            }
        }
        return cou;
    }
};