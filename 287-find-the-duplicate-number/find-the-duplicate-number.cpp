class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int i=0;
        while(i < nums.size()) {
            if(nums[i] == i+1) {
                i++;
                continue;
            }
            int seen = nums[i];
            swap(nums[i], nums[nums[i]-1]);
            if(seen == nums[i]) return seen;
        }

        return -1;
    }
};