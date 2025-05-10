class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = 9;
        vector<vector<int>> rows(9, vector<int>(9));
        vector<vector<int>> cols(9, vector<int>(9));
        vector<vector<int>> sub_grids(9, vector<int>(9));

        for(int i=0; i < size; i++) {
            for(int j=0; j < size; j++) {
                if(board[i][j] == '.') continue;

                int val = board[i][j] - '0';
                int idx = (i / 3) * 3 + (j / 3);
                if(rows[i][val-1] == val || cols[j][val-1] == val || sub_grids[idx][val-1] == val) return false;
                rows[i][val-1] = val;
                cols[j][val-1] = val;
                sub_grids[idx][val-1] = val;
            }
        }

        return true;
    }
};