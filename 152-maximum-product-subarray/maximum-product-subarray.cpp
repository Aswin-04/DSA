class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1;
        int suff = 1;
        int res = INT_MIN;
        int n = nums.size();

        for(int i=0; i < n; i++) {

            pref*=nums[i];
            suff*=nums[n-i-1];
            res = max(res, max(pref, suff));

            if(pref == 0) pref=1;
            if(suff == 0) suff=1;
        }

        return res;
    }
};