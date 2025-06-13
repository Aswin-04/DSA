class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // TC --> O(size * size);
        // SC --> O(size * size);

        const int size = 9;
        vector<unordered_set<char>> rows(size);
        vector<unordered_set<char>> cols(size);
        map<pair<int,  int>, unordered_set<char>> sub_grids;

        for(int i=0; i < size; i++) {
            for(int j=0; j < size; j++) {
                char val = board[i][j];
                if(val == '.') continue;
                pair<int, int> idx = {i/3, j/3};
                if(rows[i].count(val) || cols[j].count(val) || sub_grids[idx].count(val)) return false;
                rows[i].insert(val);
                cols[j].insert(val);
                sub_grids[idx].insert(val);
            }
        }

        return true;
    }
};