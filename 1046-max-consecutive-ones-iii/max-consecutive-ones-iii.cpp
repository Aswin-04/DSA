class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l=0;
        int zeros = 0;
        int res = 0;

        for(int r=0; r < nums.size(); r++) {  // O(N)
            if(nums[r] == 0) zeros++;
            while(zeros > k) {       // O(N) thorughtout the program at worst case
                if(nums[l] == 0) zeros--;
                l++;
            }
            res = max(res, r-l+1);
        }

        return res;

        // TC --> O(2N) & SC --> O(1)
    }
};