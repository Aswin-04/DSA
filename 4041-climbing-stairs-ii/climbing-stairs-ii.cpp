class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return recc(n, costs, dp);
    }

    int recc(int n, vector<int>& costs, vector<int>& dp) {
        if(n < 0) return INT_MAX;
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        int res = INT_MAX;
        for(int i=1; i <= 3; i++) {
            int rv = recc(n-i, costs, dp);
            if(rv != INT_MAX) {
                res = min(res, costs[n-1] + (i*i) + rv);
            }
        }

        return dp[n] = res;
    }
};