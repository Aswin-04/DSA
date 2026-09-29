class Solution {
    public int removeDuplicates(int[] nums) {
        int ptr = 1;
        int i = 0;
        
        while(ptr < nums.length) {
            if(nums[i] == nums[ptr]) ptr++;
            else {
                int temp = nums[i+1];
                nums[i+1] = nums[ptr];
                nums[ptr] = temp;
                i++;
                ptr++;
            }

        }

        return i+1;
    }
}