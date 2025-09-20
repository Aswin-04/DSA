class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recc(m-1, n-1, dp, grid);
    }

private:
    int recc(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if(m < 0 || n < 0) return INT_MAX;
        if(m == 0 && n == 0) return grid[m][n];
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = grid[m][n] + min(recc(m-1, n, dp, grid), recc(m, n-1, dp, grid));
    }
};