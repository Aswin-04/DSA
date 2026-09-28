class Solution {
    public void rotate(int[] nums, int k) {

        k%=nums.length;

        reverse(nums);
        reverse(nums, 0, k);
        reverse(nums, k, nums.length);
    }

    private void reverse(int[] nums) {
        reverse(nums, 0, nums.length);
    }

    private void reverse(int[] nums, int start, int end) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end-1];
            nums[end-1] = temp;
            start++;
            end--;
        }
    }
}