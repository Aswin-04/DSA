class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxCnt = 0;
        int zeroCnt = 0;
        int i=0;
        int j=0;

        while(j < nums.size()) {
            
            if(nums[j] == 0) zeroCnt++;
            while(zeroCnt > 1) {
                if(nums[i] == 0) zeroCnt--;
                i++;
            }

            maxCnt = max(maxCnt, j-i+1-zeroCnt);
            j++;
        }

        return maxCnt == nums.size() ? maxCnt-1 : maxCnt;
    }
};