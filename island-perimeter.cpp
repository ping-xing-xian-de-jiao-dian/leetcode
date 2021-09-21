class Solution {
private:
    int rows, cols;

public:
    int cal(int i, int j, vector<vector<int>>& grid){
        int cou = 0;
        cou += (i == 0) + (j == 0) + (i == rows - 1) + (j == cols - 1);
        cou += (i < rows - 1 && !grid[i + 1][j]) + (i > 0 && !grid[i - 1][j]);
        cou += (j < cols - 1 && !grid[i][j + 1]) + (j > 0 && !grid[i][j - 1]);
        return cou;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int cou = 0;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j])
                    cou += cal(i, j, grid);
            }
        }
        return cou;
    }
};