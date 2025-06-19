class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // NGE
        int n = temperatures.size();
        stack<int> nge_stk;
        vector<int> answer(n, 0);
        for(int i=n-1;i >= 0; i--) {
            while(!nge_stk.empty() && temperatures[i] >= temperatures[nge_stk.top()]) {
                nge_stk.pop();
            }
            
            if(!nge_stk.empty()) answer[i] = nge_stk.top() - i;
            nge_stk.push(i);
        }
        return answer;
    }
};