class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return recc(n-1, 3, dp, arr);
        
    }
    
  private:
    int recc(int day, int last, vector<vector<int>>& dp, vector<vector<int>>& arr) {
        
        if(dp[day][last] != -1) return dp[day][last];
        if(day == 0) {
            int mx = 0;
            for(int i=0; i <= 2; i++) {
                if(i == last) continue;
                mx = max(mx, arr[0][i]);
            }
            return dp[day][last] = mx;
        }
        
        int mx = 0;
        for(int i=0; i <= 2; i++) {
            if(i == last) continue;
            mx = max(mx, arr[day][i] + recc(day-1, i, dp, arr));
        }
        
        return dp[day][last] = mx;
    }
};