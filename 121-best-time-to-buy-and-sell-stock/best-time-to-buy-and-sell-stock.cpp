class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxRight(n, 0);
        int maxi = 0;
        for(int i=n-1; i >= 0; i--) {
            maxRight[i] = maxi;
            maxi = max(maxi, prices[i]);
        }

        int ans = 0;
        for(int i=0; i < n; i++) {
            ans = max(ans, maxRight[i]-prices[i]);
        }

        return ans;
    }
};