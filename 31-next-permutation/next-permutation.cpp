class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp=-1;
        int n = nums.size();
        for(int i=n-1; i>0; i--) {
            if(nums[i] > nums[i-1]) {
                bp = i-1;
                break;
            }
        }

        if(bp == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int low = bp+1;
        int high = n-1;
        int index = -1;
        while(low <= high) {
            int mid = low + ((high-low) >> 1);
            if(nums[mid] > nums[bp]) {
                index = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        swap(nums[bp], nums[index]);
        reverse(nums.begin()+bp+1, nums.end());
    }
};