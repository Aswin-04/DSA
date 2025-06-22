class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int l=0;
        int r=n-1;

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