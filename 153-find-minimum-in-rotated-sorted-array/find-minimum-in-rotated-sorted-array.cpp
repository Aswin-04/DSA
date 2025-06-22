class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        if(nums[0] < nums[n-1]) return nums[0];
        if(nums[n-2] > nums[n-1]) return nums[n-1];

        int l=1;
        int r=n-2;

        int mn = INT_MAX;
        while(l <= r) {
            int m = (l+r)/2;
            
            if(nums[l] <= nums[m]) {
                mn = min(mn, nums[l]);
                l=m+1;
            }

            else {
                mn = min(mn, nums[m]);
                r=m-1;
            }
        }

        return mn;
    }
};