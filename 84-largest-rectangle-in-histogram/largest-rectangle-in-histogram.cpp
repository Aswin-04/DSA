class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> stk;
        vector<int> nse(n, n);

        for(int i=n-1; i >= 0; i--) {

            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if(!stk.empty()) nse[i] = stk.top();
            stk.push(i);
        }

        while(!stk.empty()) {
            stk.pop();
        }

        int maxArea = 0;

        for(int i=0; i < n; i++) {
            int pse=-1;
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }

            if(!stk.empty()) pse = stk.top();
            stk.push(i);
            
            nse[i]-=1;
            pse+=1;
            int crntArea = heights[i] * (nse[i]-pse+1);
            maxArea = max(maxArea, crntArea);
        }

        return maxArea;
    }
};