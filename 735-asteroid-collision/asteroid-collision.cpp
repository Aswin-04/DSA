class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;

        for(int i=0; i < n; i++) {
            if(asteroids[i] > 0 || stk.empty()) {
                stk.push(asteroids[i]);
            }

            else {
                while(!stk.empty() && stk.top() > 0 && abs(asteroids[i]) > stk.top()) {
                    stk.pop();
                }

                if(!stk.empty() && stk.top() == abs(asteroids[i])) stk.pop();
                else if(stk.empty() || stk.top() < 0) stk.push(asteroids[i]);
            }
        }

        vector<int> ans(stk.size());
        for(int i= stk.size()-1; i >= 0; i--) {
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }
};