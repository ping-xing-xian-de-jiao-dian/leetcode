class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[301][301];
        memset(dp, 0, sizeof(dp));
        int maxi = 0;
        // dp[i][j]表示以ij为右下角的最大正方形边长
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1])，，还有dp[i - 边长][j - 边长] == 1
        for (int i = 0; i < matrix.size(); ++i) dp[i][0] = matrix[i][0] - 48, maxi = max(maxi, dp[i][0]);
        for (int i = 0; i < matrix[0].size(); ++i) dp[0][i] = matrix[0][i] - 48, maxi = max(maxi, dp[0][i]);
        for (int i = 1; i < matrix.size(); ++i){
            for (int j = 1; j < matrix[0].size(); ++j){
                if (matrix[i][j] == '0') continue;
                int edge = min(dp[i - 1][j], dp[i][j - 1]);
                if (matrix[i - edge][j - edge] == '1') dp[i][j] = edge + 1;
                else dp[i][j] = edge;
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi * maxi;
    }
};