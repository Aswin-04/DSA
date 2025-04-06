class Solution {
public:
    int helper(vector<int> nums, int goal) {
        if(goal < 0) return 0;
        int l=0; 
        int n = nums.size();
        int sum = 0;
        int res = 0;
        for(int r=0; r < n; r++) {
            sum+=nums[r];
            while(sum > goal) {
                sum-=nums[l];
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
    // TC --> O(2N + 2N)  &  SC --> O(1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};