class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<int>> rows;
        unordered_map<int, set<int>> cols;
        map<pair<int, int>, set<int>> sub_grids;

        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[i].size(); j++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                if(rows[i].count(num) || cols[j].count(num) || sub_grids[{i/3, j/3}].count(num)) return false;
                rows[i].insert(num);
                cols[j].insert(num);
                sub_grids[{i/3, j/3}].insert(num);
            }
        }

        return true;

    }
};