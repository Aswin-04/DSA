class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return recc(0, n, dp);
    }
private:
    int recc(int level, int n, vector<int>& dp) {
        
        // pruning
        if(level > n) return 0;

        // basecase
        if(level == n) return 1;

        // 
        if(dp[level] != -1) return dp[level];

        // transition
        return dp[level] = recc(level+1, n, dp) + recc(level+2, n, dp);
    }
};