class Solution {
public:
    int trap(vector<int>& height) {

        // TC --> O(N)
        // SC --> O(N)

        int n = height.size();
        vector<int> maxRight(n, 0);

        int maxi = 0;
        for(int i=n-1; i >= 0; i--) {
            maxRight[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        int ans = 0;
        int maxLeft = 0;
        for(int i=0; i < n; i++) {
            int waterTrapped = min(maxLeft, maxRight[i]) - height[i];
            maxLeft = max(maxLeft, height[i]);
            ans+=max(waterTrapped, 0);
        }

        return ans;
    }
};