class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> answer(n);
        answer[n-1] = 0;
        stk.push(n-1);
        for(int i=n-2; i >= 0; i--) {
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }

            if(stk.empty()) answer[i] = 0;
            else answer[i] = stk.top() - i;
            stk.push(i);
        }

        return answer;
    }
};