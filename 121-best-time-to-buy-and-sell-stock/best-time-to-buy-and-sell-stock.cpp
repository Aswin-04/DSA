class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // TC --> O(N)
        // SC --> O(1)

        int n = prices.size();
        int mx = prices[n-1];
        int ans = 0;

        for(int i=n-2; i >= 0; i--) {
            ans = max(ans, mx-prices[i]);
            mx = max(mx, prices[i]);
        } 

        return ans;
    }
};