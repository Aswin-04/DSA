class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int,int>> stk_p, stk_n;

        for(int i=0; i<n; i++) left[i] = i+1;
        for(int i=0; i<n; i++) right[i] = n-i;

        for(int i=0; i < n; i++) {
            while(!stk_p.empty() && stk_p.top().first > arr[i]) stk_p.pop();
            if(!stk_p.empty()) left[i] = i - stk_p.top().second;
            stk_p.push({arr[i], i});

            while(!stk_n.empty() && stk_n.top().first > arr[i]) {
                auto x = stk_n.top();
                stk_n.pop();
                right[x.second] = i - x.second;
            }
            stk_n.push({arr[i], i});
        }

        int ans = 0, mod = 1e9+7;
        for(int i=0; i < n; i++) {
            ans = (ans+(1LL*arr[i]*left[i]*right[i]))%mod;
        }

        return ans;
    }
};