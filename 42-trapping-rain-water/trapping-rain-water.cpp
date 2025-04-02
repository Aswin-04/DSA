class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int total = 0;

        while(l <= r) {
            if(leftMax <= rightMax) {
                int res = leftMax-height[l];
                total+= (res<0) ? 0 : res;
                leftMax = max(leftMax, height[l]);
                l++;
            }

            else {
                int res = rightMax-height[r];
                total+=(res<0) ? 0: res;
                rightMax = max(rightMax, height[r]);
                r--;
            }
        }

        return total;
    }
};