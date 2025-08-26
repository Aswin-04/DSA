class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, res);
        return res;
    }
private: 
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& res) {
        if(col == n) {
            res.push_back(board);
            return;
        }

        for(int row=0; row < n; row++) {
            if(isValid(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col+1, n, board, res);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, int n, vector<string>& board) {

        // col check;
        for(int i=0; i < col; i++) {
            if(board[row][i] == 'Q') return false;
        }

        // lower diagonal check
        int tempRow = row;
        int tempCol = col;
        row++;
        col--;

        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        row = tempRow;
        col = tempCol;
        row--;
        col--;

        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        return true;
    }
};