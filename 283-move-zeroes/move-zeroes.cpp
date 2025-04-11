class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i=0, index=0; i < n; i++) {
            if(nums[i]) swap(nums[index++], nums[i]);
        }
    }
};