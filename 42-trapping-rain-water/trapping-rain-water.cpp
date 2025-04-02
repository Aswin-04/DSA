class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxi = 0;
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);

        for(int i=0; i < n; i++) {
            prefixMax[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        maxi = 0;
        for(int i=n-1; i >= 0; i--) {
            suffixMax[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        int totalWater = 0;
        for(int i=0; i < n; i++) {
            int trapped = min(prefixMax[i], suffixMax[i]) - height[i];
            if(trapped < 0) trapped = 0;
            totalWater+=trapped;
        }

        return totalWater;
    }
};