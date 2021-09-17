class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int blocks[9][9] = {0};
        size_t row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (board[i][j] == '.') continue;
                int temp = board[i][j] - 48 - 1;
                if (rows[i][temp] || cols[j][temp] || blocks[i / 3 * 3 + j / 3][temp]) return 0;
                rows[i][temp] = cols[j][temp] = blocks[i / 3 * 3 + j / 3][temp] = 1;
            }
        }
        return 1;
    }
};