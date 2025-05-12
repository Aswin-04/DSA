class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        int mx = 0;
        for(int i=0; i < n; i++) {
            if(mx > height[i]) {
                prefix[i] = mx;
            }
            mx = max(mx, height[i]);
        }
        mx = 0;
        for(int i=n-1; i >= 0; i--) {
            if(mx > height[i]) {
                suffix[i] = mx;
            }
            mx = max(mx, height[i]);
        }

        int res = 0;
        for(int i=0; i < n; i++) {
            int trapped = min(prefix[i], suffix[i]) - height[i];
            res+=max(0, trapped);
        }

        return res;
    }
};