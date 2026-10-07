class Solution {
    public void nextPermutation(int[] nums) {
        int bp = -1;
        int n = nums.length;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                bp = i;
                break;
            }
        }

        if (bp == -1) {
            reverse(nums, 0);
            return;
        }

        int low = bp + 1;
        int high = n - 1;
        int sm = bp + 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > nums[bp]) {
                sm = mid;
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        swap(nums, bp, sm);
        reverse(nums, bp + 1);
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void reverse(int[] nums, int start) {
        int end = nums.length - 1;

        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
}