class Solution {
    public void moveZeroes(int[] nums) {
        int ptr = -1;
        for(int i=0; i < nums.length; i++) {
            if(nums[i] != 0) {
                ++ptr;
                int temp = nums[ptr];
                nums[ptr] = nums[i];
                nums[i] = temp;            
            } 
        }
    }
}