class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return recc(n, dp);
    }
private:
    int recc(int level, vector<int>& dp) {
        
        // pruning
        if(level < 0) return 0;

        // basecase
        if(level == 0 || level == 1) return 1;

        // cache
        if(dp[level] != -1) return dp[level];

        // transition
        return dp[level] = recc(level-1, dp) + recc(level-2, dp);
    }
};