class Solution {
public:
    int distance2(const vector<int>& p1, const vector<int>& p2){
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        size_t len = points.size();
        if (len < 3) return 0;
        int count = 0;
        for (const auto& p1 : points){
            unordered_map<int, int> dis_count;
            for (const auto& p2 : points){
                dis_count[distance2(p1, p2)]++;
            }
            for (const auto& [_, cou] : dis_count){
                count += cou * (cou - 1);
            }
        }
        return count;
    }
};