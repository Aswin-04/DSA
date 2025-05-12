class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j=n-1;
        long long max_area = 0;

        while(i < j) {
            long long crnt_area = 1LL * (j-i) * min(height[i], height[j]);
            max_area = max(max_area, crnt_area);
            if(height[i] <= height[j]) i++;
            else j--;
        }

        return max_area;
    }
};