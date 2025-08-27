class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0);
        vector<int> lowerDiagonal(n+n-1, 0);
        vector<int> upperDiagonal(n+n-1, 0);
        solve(0, n, leftRow, lowerDiagonal, upperDiagonal, board, res);
        return res;
    }
private: 
    void solve(int col, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, vector<string>& board, vector<vector<string>>& res) {
        if(col == n) {
            res.push_back(board);
            return;
        }

        for(int row=0; row < n; row++) {
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, n, leftRow, lowerDiagonal, upperDiagonal, board, res);
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
                board[row][col] = '.';
            }
        }
    }

};