class Solution {
    public int[] searchRange(int[] nums, int target) {

        int low = 0;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        if (high == -1 || nums[high] != target)
            return new int[] { -1, -1 };

        int[] res = new int[2];
        res[1] = high;

        low = 0;
        high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
                high = mid - 1;

            else
                low = mid + 1;
        }

        res[0] = low;
        return res;
    }
}