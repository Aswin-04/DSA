class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int totzero = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]==0) totzero++;
        }
        int cnt=0;
        for(int i=n-1; i>= n - totzero; i--) {
            if(nums[i]==0) cnt++;
        }
        return totzero - cnt;
    }
};