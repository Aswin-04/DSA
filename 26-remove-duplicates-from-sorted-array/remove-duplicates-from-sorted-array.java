class Solution {
    public int removeDuplicates(int[] nums) {
        int ptr = 1;
        int i = 0;
        
        while(ptr < nums.length) {
            if(nums[i] != nums[ptr]) {
                nums[i+1] = nums[ptr];
                i++;
            } 
            ptr++;
        }

        return i+1;
    }
}