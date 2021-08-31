class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res;
        vector<vector<int>> lr(n + 2, vector<int>(2, 0));
        for (const auto& booking : bookings){
            lr[booking[0]][0] += booking[2];
            lr[booking[1] + 1][1] += booking[2];
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i){
            sum += lr[i][0] - lr[i][1];
            res.emplace_back(sum);
        }
        return res;
    }
};