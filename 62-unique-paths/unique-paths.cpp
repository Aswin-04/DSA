class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recc(m-1, n-1, dp);
    }     

    int recc(int m, int n, vector<vector<int>>& dp) {
        if(n == 0 && m == 0) return 1;
        if(n < 0 || m < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = recc(m-1, n, dp) + recc(m, n-1, dp);
    }
};