class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = prices[n-1];
        int ans = 0;
        for(int i=n-2; i >= 0; i--) {
            if(prices[i] > mx) mx = prices[i];
            ans = max(ans, max(0, mx-prices[i]));
        }

        return ans;
    }
};