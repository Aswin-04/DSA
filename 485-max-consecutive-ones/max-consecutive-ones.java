class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0;
        int maxCnt = 0;

        for(int i=0; i < nums.length; i++) {
            if(nums[i] == 0) {
                maxCnt = Integer.max(cnt, maxCnt);
                cnt = 0;
            }

            else cnt++;
        }

        maxCnt = Integer.max(cnt, maxCnt);
        return maxCnt;
    }
}