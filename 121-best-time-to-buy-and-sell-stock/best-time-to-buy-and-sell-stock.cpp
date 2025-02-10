class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int profit = 0;
        int mini = prices[0];

        for(int i=1; i < prices.size(); i++) {
            if(prices[i] < mini) mini=prices[i];
            else max_profit = max(max_profit, prices[i]-mini);
        }
        return max_profit;
    }
};