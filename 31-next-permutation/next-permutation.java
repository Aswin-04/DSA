class Solution {
    public void nextPermutation(int[] nums) {
        int bp = -1;
        int n = nums.length;

        for(int i=n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                bp = i;
                break;
            }
        }

        if(bp == -1) {
            reverse(nums, 0);
            return;
        }

        int sm = bp+1;

        for(int i=bp+1; i < n; i++) {
            if(nums[i] > nums[bp] && nums[i] <= nums[sm]) {
                sm = i;
            }
        }

        swap(nums, bp, sm);
        reverse(nums, bp+1);
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void reverse(int[] nums, int start) {
        int end = nums.length-1;

        while(start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
}