class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        while(k--) {
            vector<vector<int>> ans(n, vector<int>(m));
            for(int i=0; i<n; i++) {
                for(int j=0; j<m-1; j++) {
                    ans[i][j+1] = grid[i][j];
                }
                ans[(i+1)%n][0] = grid[i][m-1];
            }
            grid = ans;
        }
        return grid;
    }
};