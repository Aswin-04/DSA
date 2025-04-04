class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l=0;
        int r=0;
        int zeros = 0;
        int cnt = 0;
        int maxLen = 0;

        while(l <= r && r < nums.size()) {
            if(nums[r] == 0) zeros++;
            if(zeros > k) {
                while(nums[l] == 1) l++;
                zeros--;
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};