class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int ans = INT_MAX;
        vector<int> answer;
        for(int i=0; i < cost.size(); i++) {
            ans = min(ans, cost[i]);
            answer.push_back(ans);
        }

        return answer;
    }
};