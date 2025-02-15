class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low=0;
        int high = nums.size()-1;

        if(nums.size() == 1) return nums[0];
        if(nums[low] != nums[low+1]) return nums[low];
        if(nums[high-1] != nums[high]) return nums[high];

        low++;
        high--;

        while(low <= high) {
            int mid = low + ((high-low) >> 2);
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            else if(nums[mid-1] == nums[mid]) {
                if(mid%2 == 0) high = mid-1;
                else low = mid+1;
            }
            else {
                if(mid%2 == 1) high = mid-1;
                else low = mid+1;
            }
        } 

        return -1;
    }
};