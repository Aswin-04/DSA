class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left = 0;
        int right = n-1;
        if(n == 1) return nums[0];
        if(nums[left] != nums[left+1]) return nums[left];
        if(nums[right] != nums[right-1]) return nums[right];

        left++;
        right++;

        while(left <= right) {
            int mid = left + ((right-left) >> 1);
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if(mid&1) {
                if(nums[mid] != nums[mid-1]) right = mid-1;
                else left = mid+1;
            }
            else {
                if(nums[mid] != nums[mid+1]) right = mid-1;
                else left = mid+1;
            }
        }

        return -1;
    }
};